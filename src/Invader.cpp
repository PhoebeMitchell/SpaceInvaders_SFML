//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/Invader.h"
#include "../headers/InvaderController.h"
#include "../headers/Collision.h"
#include <iostream>

const int INVADER_SPRITE_COLUMNS = 2;

Invader::Invader(Time *time, Window *window, std::string spritePath, InvaderController *invaderController, Collision *playerCollision, Collision *invaderCollision, int rowNumber, int columnNumber) : Object(time, window) {
    _invaderController = invaderController;
    _playerCollision = playerCollision;
    _invaderCollision = _invaderCollision;
    _rowNumber = rowNumber;
    _columnNumber = columnNumber;
    auto sprite = LoadSprite(spritePath);
    sprite->SetScale(INVADER_SCALE, INVADER_SCALE);
    sprite->SetColumnCount(INVADER_SPRITE_COLUMNS);
}

void Invader::Update() {
    Time *time = GetTime();
    if (_shouldMoveAfterDelay && time->GetCurrentTime() - _moveAfterDelayCallTime > _moveDelay) {
        SetPosition(_xDirection, _yDirection, true);
        IncrementSprite();
        _shouldMoveAfterDelay = false;
    }
    if (_canShoot && time->GetCurrentTime() > _nextShootTime) {
        Shoot();
    }

    for (auto i = 0; i < _bullets.size(); i++) {
        _bullets[i]->Update();
    }

    Object::Update();
}

bool Invader::IsAlive() {
    return _isAlive;
}

void Invader::IncrementSprite() {
    auto sprite = GetSprite();
    sprite->SetFrame((sprite->GetCurrentFrame() + 1) % sprite->GetColumnCount());
}

void Invader::MoveAfterDelay(float x, float y, float delay) {
    _shouldMoveAfterDelay = true;
    _moveAfterDelayCallTime = GetTime()->GetCurrentTime();
    _xDirection = x;
    _yDirection = y;
    _moveDelay = delay;
}

void Invader::SetCanShoot(bool canShoot) {
    _canShoot = canShoot;
    CalculateNextShootTime(GetTime());
}

void Invader::Shoot() {
    _bullets.push_back(std::make_unique<Bullet>(GetTime(), GetWindow(), BULLET_VELOCITY, GetPosition() + (sf::Vector2f){GetSize().x / 2, GetSize().y / 2}, _playerCollision, _invaderCollision));
    _bullets[_bullets.size() - 1]->GetSprite()->SetOrigin(0.5f, 0);
    CalculateNextShootTime(GetTime());
}

void Invader::CalculateNextShootTime(Time *time) {
    _nextShootTime = time->GetCurrentTime() + MIN_SHOOT_DELAY + ((MAX_SHOOT_DELAY - MIN_SHOOT_DELAY) * ((float)rand() / RAND_MAX));
}

void Invader::Destroy() {
    _invaderController->KillInvader(_rowNumber, _columnNumber);
    _isAlive = false;
    SetCollisionActive(false);
}
