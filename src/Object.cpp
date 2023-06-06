//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Object.h"
#include "../headers/Window.h"

Object::Object(Game *game) {
    game->AddObject(this);
}

void Object::Update(Window *window, float timeDelta) {
    window->Draw(_sprite->GetDrawable());
}

void Object::SetPosition(int x, int y, bool relative) {
    if (relative) {
        auto position = _sprite->GetPosition();
        x += position.x;
        y += position.y;
    }
    _sprite->SetPosition(x, y);
}

void Object::SetSprite(std::unique_ptr<Sprite> *sprite) {
    _sprite = std::move(*sprite);
}
