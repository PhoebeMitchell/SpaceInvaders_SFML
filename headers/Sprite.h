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
    void SetColumnCount(int columnCount);
    void SetScale(float x, float y);
    sf::Drawable *GetDrawable();
    sf::Vector2f GetPosition();
    sf::Vector2u GetTextureSize();
    sf::Vector2f GetScale();
    int GetCurrentFrame();
    int GetColumnCount();
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    int _columnCount = 1;
    int _currentFrame = 0;
};


#endif //SPACEINVADERS_SPRITE_H
