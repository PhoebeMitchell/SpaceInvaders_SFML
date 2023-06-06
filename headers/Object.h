//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_OBJECT_H
#define SPACEINVADERS_OBJECT_H

#include <SFML/Graphics.hpp>

class Window;
class Sprite;

class Object {
public:
    Object();

    virtual void Update(Window *window, float timeDelta);
    void SetPosition(int x, int y);
    void SetSprite(Sprite *sprite);
private:
    Sprite *_sprite;
};


#endif //SPACEINVADERS_OBJECT_H
