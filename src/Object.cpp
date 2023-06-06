//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include <iostream>
#include "../headers/Object.h"
#include "../headers/Window.h"

Object::Object(Game *game) {
    game->AddObject(this);
}

void Object::Update(Window *window, float timeDelta) {
    window->Draw(_sprite->GetDrawable());
}

void Object::SetPosition(float x, float y, bool relative) {
    std::cout << x << " " << y << std::endl;
    if (relative) {
        auto position = _sprite->GetPosition();
        x += position.x;
        y += position.y;
    }
    std::cout << x << " " << y << std::endl << std::endl;
    _sprite->SetPosition(x, y);
}

void Object::SetSprite(std::unique_ptr<Sprite> *sprite) {
    _sprite = std::move(*sprite);
}
