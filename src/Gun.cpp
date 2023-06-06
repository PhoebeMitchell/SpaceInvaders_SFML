//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Gun.h"
#include "../headers/Constants.h"

Gun::Gun(Game *game) : Object(game) {
    std::unique_ptr<Sprite> sprite = std::make_unique<Sprite>("./sprites/Gun.png", 1, 5);
    sprite->SetOrigin(0.5f, 1.0f);
    sprite->SetPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
    SetSprite(&sprite);
}

void Gun::Update(Window *window, float timeDelta) {
    Object::Update(window, timeDelta);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        SetPosition(-_speed, 0, true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        SetPosition(_speed, 0, true);
    }
}
