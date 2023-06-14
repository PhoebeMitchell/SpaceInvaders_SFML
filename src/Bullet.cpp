//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/Bullet.h"
#include "../headers/Collision.h"
#include "../headers/Invader.h"
#include "../headers/Constants.h"

const float BULLET_SCALE = 2.5f;

Bullet::Bullet(Time *time, Window *window, sf::Vector2f velocity, sf::Vector2f position, Collision *playerCollision, Collision *invaderCollision) : Object(time, window) {
    _collision = playerCollision;
    auto sprite = LoadSprite("./sprites/Bullet.png");
    _velocity = velocity;
    sprite->SetPosition(position.x, position.y);
    sprite->SetScale(BULLET_SCALE, BULLET_SCALE);
    sprite->SetOrigin(0.5f, 1);
}

void Bullet::Update() {
    auto collision = _collision->GetCollidingObject(this);
    if (collision != nullptr) {
        auto destroyable = dynamic_cast<Destroyable*>(collision);
        if (destroyable != nullptr) {
            destroyable->Destroy();
            SetPosition(-10, -100, false);
        }
    }

    SetPosition(_velocity.x * GetTime()->GetTimeDelta(), _velocity.y * GetTime()->GetTimeDelta(), true);
    Object::Update();
}

void Bullet::Destroy() {

}

bool Bullet::IsOffScreen() {
    return GetPosition().y < 0 || GetPosition().y > WINDOW_HEIGHT;
}
