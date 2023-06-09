//
// Created by Phoebe Mitchell on 07/06/2023.
//

#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H


#include "Object.h"

class Bullet : public Object {
public:
    Bullet(Time *time, Window *window, sf::Vector2f velocity, sf::Vector2f position);

    void Update() override;
    bool IsOffScreen();
private:
    sf::Vector2f _velocity;
};


#endif //SPACEINVADERS_BULLET_H
