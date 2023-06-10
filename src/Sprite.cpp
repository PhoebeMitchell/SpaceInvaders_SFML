//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Sprite.h"

Sprite::Sprite(std::string spritePath, int columnCount, int scale) {
    if (!_texture.loadFromFile(spritePath)) {
        throw std::invalid_argument("Could not open file " + spritePath);
    }
    SetFrame(0);
    _sprite.setTexture(_texture);
}

void Sprite::SetFrame(int frameNumber) {
    _currentFrame = frameNumber;
    auto textureSize = _texture.getSize();
    auto rectWidth = textureSize.x / _columnCount;
    _sprite.setTextureRect(sf::IntRect(rectWidth * frameNumber, 0, rectWidth, textureSize.y));
}

void Sprite::SetPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

sf::Drawable *Sprite::GetDrawable() {
    return &_sprite;
}

void Sprite::SetOrigin(float x, float y) {
    auto textureRect = _texture.getSize();
    _sprite.setOrigin(x * textureRect.x, y * textureRect.y);
}

sf::Vector2f Sprite::GetPosition() {
    return _sprite.getPosition();
}

void Sprite::SetColumnCount(int columnCount) {
    _columnCount = columnCount;
    SetFrame(0);
}

void Sprite::SetScale(float x, float y) {
    _sprite.setScale(x, y);
}

sf::Vector2u Sprite::GetTextureSize() {
    return _texture.getSize();
}

sf::Vector2f Sprite::GetScale() {
    return _sprite.getScale();
}

int Sprite::GetCurrentFrame() {
    return _currentFrame;
}

int Sprite::GetColumnCount() {
    return _columnCount;
}

sf::FloatRect Sprite::GetBounds() {
    return _sprite.getGlobalBounds();
}
