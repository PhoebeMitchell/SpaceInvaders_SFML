//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Gun.h"
#include "../headers/Constants.h"
#include "../headers/Collision.h"

const float SPRITE_SCALE = 5;
const sf::Vector2f BULLET_VELOCITY = {0, -600};

Gun::Gun(Time *time, Window *window, Collision *playerCollision, Collision *invaderCollision) : Object(time, window) {
    _playerCollision = playerCollision;
    _invaderCollision = invaderCollision;
    auto sprite = LoadSprite("./sprites/Gun.png");
    sprite->SetOrigin(0.5f, 1.0f);
    sprite->SetPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
    sprite->SetScale(SPRITE_SCALE, SPRITE_SCALE);
}

void Gun::Update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        SetPosition(-_speed * GetTime()->GetTimeDelta(), 0, true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        SetPosition(_speed * GetTime()->GetTimeDelta(), 0, true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!_spacePressed) {
            _bullets.push_back(std::make_unique<Bullet>(GetTime(), GetWindow(), BULLET_VELOCITY, GetPosition() - (sf::Vector2f){0, GetSize().y}, _playerCollision, _invaderCollision));
            _spacePressed = true;
        }
    }
    else {
        _spacePressed = false;
    }

    for (int i = _bullets.size() - 1; i >= 0; i--) {
        auto bullet = _bullets[i].get();
        if (bullet->IsOffScreen()) {
            _bullets.erase(_bullets.begin() + i);
            continue;
        }

        _bullets[i]->Update();
    }

    Object::Update();
}
