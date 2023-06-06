//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_SPRITE_H
#define SPACEINVADERS_SPRITE_H


#include <string>
#include <SFML/Graphics.hpp>

class Sprite {
public:
    Sprite(std::string spritePath, int columnCount);

    void SetFrame(int frameNumber);
    void SetPosition(int x, int y);
    sf::Drawable *GetDrawable();
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    int _columnCount;
};


#endif //SPACEINVADERS_SPRITE_H
