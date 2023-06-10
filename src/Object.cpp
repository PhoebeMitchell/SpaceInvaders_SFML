//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include <iostream>
#include "../headers/Object.h"
#include "../headers/Window.h"

Object::Object(Time *time, Window *window) : Updatable(time) {
    _window = window;
}

void Object::Update() {
    _window->Draw(_sprite->GetDrawable());
}

void Object::SetPosition(float x, float y, bool relative) {
    if (relative) {
        auto position = _sprite->GetPosition();
        x += position.x;
        y += position.y;
    }
    _sprite->SetPosition(x, y);
}

Sprite *Object::LoadSprite(std::string spritePath) {
    _sprite = std::make_unique<Sprite>(spritePath, 1, 1);
    return _sprite.get();
}

sf::Vector2f Object::GetPosition() {
    return _sprite->GetPosition();
}

sf::Vector2f Object::GetSize() {
    auto textureSize = _sprite->GetTextureSize();
    auto scale = _sprite->GetScale();
    return {textureSize.x * scale.x, textureSize.y * scale.y};
}

Sprite *Object::GetSprite() {
    return _sprite.get();
}

Window *Object::GetWindow() {
    return _window;
}

bool Object::IsCollisionActive() {
    return _isCollisionActive;
}

void Object::SetCollisionActive(bool isCollisionActive) {
    _isCollisionActive = isCollisionActive;
}
