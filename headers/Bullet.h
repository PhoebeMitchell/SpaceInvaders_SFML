//
// Created by Phoebe Mitchell on 07/06/2023.
//

#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H


#include "Object.h"

class Collision;

class Bullet : public Object {
public:
    Bullet(Time *time, Window *window, sf::Vector2f velocity, sf::Vector2f position, Collision *playerCollision,
           Collision *invaderCollision);

    void Update() override;
    bool IsOffScreen();
private:
    void CheckCollisions();

    Collision *_collision;
    sf::Vector2f _velocity;
};


#endif //SPACEINVADERS_BULLET_H
