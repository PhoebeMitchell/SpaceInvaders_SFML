//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_GUN_H
#define SPACEINVADERS_GUN_H

#include "Object.h"
#include "Bullet.h"
#include <memory>

class Collision;

class Gun : public Object {
public:
    Gun(Time *time, Window *window, Collision *collision);

    void Update() override;
private:
    Collision *_collision;
    float _speed = 500;
    bool _spacePressed;
    std::vector<std::unique_ptr<Bullet>> _bullets;
};


#endif //SPACEINVADERS_GUN_H
