//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/Invader.h"
#include "../headers/InvaderController.h"

const int INVADER_SPRITE_COLUMNS = 2;

Invader::Invader(Time *time, Window *window, std::string spritePath, InvaderController *invaderController) : Object(time, window) {
    _invaderController = invaderController;
    auto sprite = LoadSprite(spritePath);
    sprite->SetScale(INVADER_SCALE, INVADER_SCALE);
    sprite->SetColumnCount(INVADER_SPRITE_COLUMNS);
}

void Invader::Update() {
    if (_shouldMoveAfterDelay && GetTime()->GetCurrentTime() - _moveAfterDelayCallTime > _moveDelay) {
        SetPosition(_xDirection, _yDirection, true);
        IncrementSprite();
        _shouldMoveAfterDelay = false;
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

void Invader::Die() {
    _invaderController->DecrementInvaderCount();
    _isAlive = false;
    SetCollisionActive(false);
}
