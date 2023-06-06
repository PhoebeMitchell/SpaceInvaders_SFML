//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_GUN_H
#define SPACEINVADERS_GUN_H

#include "Object.h"

class Gun : private Object {
public:
    Gun(Game *game);

    void Update(Window *window, float timeDelta) override;
private:
    float _speed = 5;
};


#endif //SPACEINVADERS_GUN_H
