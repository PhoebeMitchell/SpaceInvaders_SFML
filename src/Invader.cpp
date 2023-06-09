//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/Invader.h"

const int INVADER_SPRITE_COLUMNS = 2;

Invader::Invader(Time *time, Window *window, std::string spritePath) : Object(time, window) {
    auto sprite = LoadSprite(spritePath);
    sprite->SetScale(INVADER_SCALE, INVADER_SCALE);
    sprite->SetColumnCount(INVADER_SPRITE_COLUMNS);
}

void Invader::Update() {
    if (GetTime()->GetCurrentTime() - _lastMovementTime > 1) {
        Move(GetTime());
    }
    Object::Update();
}

void Invader::Move(Time *time) {
    _lastMovementTime = time->GetCurrentTime();
    auto sprite = GetSprite();
    sprite->SetFrame((sprite->GetCurrentFrame() + 1) % sprite->GetColumnCount());
}

bool Invader::IsAlive() {
    return _isAlive;
}
