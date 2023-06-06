//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_SPRITE_H
#define SPACEINVADERS_SPRITE_H


#include <string>
#include <SFML/Graphics.hpp>

class Sprite {
public:
    Sprite(std::string spritePath, int columnCount, int scale);

    void SetFrame(int frameNumber);
    void SetPosition(float x, float y);
    void SetOrigin(float x, float y);
    sf::Drawable *GetDrawable();
    sf::Vector2f GetPosition();
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    int _columnCount;
};


#endif //SPACEINVADERS_SPRITE_H
