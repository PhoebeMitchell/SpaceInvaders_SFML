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

    void Draw(Window *window);
    void SetPosition(int x, int y);
    void SetSprite(Sprite *sprite);
private:
    Sprite *_sprite;
};


#endif //SPACEINVADERS_OBJECT_H
