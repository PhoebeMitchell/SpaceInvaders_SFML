//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Object.h"
#include "../headers/Window.h"
#include "../headers/Sprite.h"

Object::Object() {

}

void Object::Draw(Window *window) {
    window->Draw(_sprite->GetDrawable());
}

void Object::SetPosition(int x, int y) {
    _sprite->SetPosition(x, y);
}

void Object::SetSprite(Sprite *sprite) {
    _sprite = sprite;
}
