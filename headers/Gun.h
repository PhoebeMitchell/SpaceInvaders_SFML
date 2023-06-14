//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_GUN_H
#define SPACEINVADERS_GUN_H

#include "Object.h"
#include "Bullet.h"
#include "Destroyable.h"
#include <memory>

class Collision;

class Gun : public Object, public Destroyable {
public:
    Gun(Time *time, Window *window, Collision *playerCollision, Collision *invaderCollision);

    void Update() override;
    void Destroy() override;
private:
    Collision *_playerCollision;
    Collision *_invaderCollision;
    float _speed = 500;
    bool _spacePressed;
    std::vector<std::unique_ptr<Bullet>> _bullets;
};


#endif //SPACEINVADERS_GUN_H
