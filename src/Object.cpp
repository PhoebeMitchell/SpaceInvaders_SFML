//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Object.h"
#include "../headers/Window.h"

Object::Object(std::string spritePath) {
    sf::Texture texture;
    if (!texture.loadFromFile(spritePath)) {
        throw std::invalid_argument("Could not open file " + spritePath);
    }
    _sprite.setTexture(texture);
}

void Object::Draw(Window *window) {
    window->Draw(&_sprite);
}

void Object::SetPosition(int x, int y) {
    _sprite.setPosition(x, y);
}
