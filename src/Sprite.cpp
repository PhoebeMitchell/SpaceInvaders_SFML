//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Sprite.h"

Sprite::Sprite(std::string spritePath, int columnCount) {
    if (!_texture.loadFromFile(spritePath)) {
        throw std::invalid_argument("Could not open file " + spritePath);
    }
    _columnCount = columnCount;
    SetFrame(0);
    _sprite.setTexture(_texture);
}

void Sprite::SetFrame(int frameNumber) {
    auto textureSize = _texture.getSize();
    auto rectWidth = textureSize.x / _columnCount;
    _sprite.setTextureRect(sf::IntRect(rectWidth * frameNumber, 0, rectWidth, textureSize.y));
}

void Sprite::SetPosition(int x, int y) {
    _sprite.setPosition(x, y);
}

sf::Drawable *Sprite::GetDrawable() {
    return &_sprite;
}
