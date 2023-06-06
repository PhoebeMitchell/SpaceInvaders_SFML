//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_OBJECT_H
#define SPACEINVADERS_OBJECT_H

#include <SFML/Graphics.hpp>
#include "../headers/Sprite.h"
#include "../headers/Game.h"

class Window;

class Object {
public:
    Object(Game *game);

    virtual void Update(Window *window, float timeDelta);
    void SetPosition(float x, float y, bool relative);
    void SetSprite(std::unique_ptr<Sprite> *sprite);
private:
    std::unique_ptr<Sprite> _sprite;
};


#endif //SPACEINVADERS_OBJECT_H
