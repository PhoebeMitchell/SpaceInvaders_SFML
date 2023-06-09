//
// Created by Phoebe Mitchell on 07/06/2023.
//

#ifndef SPACEINVADERS_INVADER_H
#define SPACEINVADERS_INVADER_H

#include <SFML/System/Vector2.hpp>
#include "Object.h"

class Invader : public Object {
public:
    Invader(Time *time, Window *window, std::string spritePath);

    static const int INVADER_SCALE = 2;

    void Update() override;
    bool IsAlive();
    void IncrementSprite();
    void MoveAfterDelay(float x, float y, float delay);
private:
    bool _shouldMoveAfterDelay = false;
    float _moveAfterDelayCallTime = 0;
    float _xDirection = 0;
    float _yDirection = 0;
    float _moveDelay = 0;
    bool _isAlive = 1;
};


#endif //SPACEINVADERS_INVADER_H
