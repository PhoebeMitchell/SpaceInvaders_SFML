//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/Bullet.h"

const float BULLET_SCALE = 2.5f;

Bullet::Bullet(Time *time, Window *window, sf::Vector2f velocity, sf::Vector2f position) : Object(time, window) {
    auto sprite = LoadSprite("./sprites/Bullet.png");
    _velocity = velocity;
    sprite->SetPosition(position.x, position.y);
    sprite->SetScale(BULLET_SCALE, BULLET_SCALE);
    sprite->SetOrigin(0.5f, 1);
}

void Bullet::Update() {
    SetPosition(_velocity.x * GetTime()->GetTimeDelta(), _velocity.y * GetTime()->GetTimeDelta(), true);
    Object::Update();
}

bool Bullet::IsOffScreen() {
    return GetPosition().y < 0;
}
