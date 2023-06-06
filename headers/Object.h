//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_OBJECT_H
#define SPACEINVADERS_OBJECT_H

#include <SFML/Graphics.hpp>

class Window;

class Object {
public:
    Object(std::string spritePath);

    void Draw(Window *window);
    void SetPosition(int x, int y);
private:
    sf::Sprite _sprite;
};


#endif //SPACEINVADERS_OBJECT_H
