//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include <iostream>
#include "../headers/Gun.h"
#include "../headers/Constants.h"

Gun::Gun(Game *game) : Object(game) {
    std::unique_ptr<Sprite> sprite = std::make_unique<Sprite>("./sprites/Gun.png", 1, 5);
    sprite->SetOrigin(0.5f, 1.0f);
    sprite->SetPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
    SetSprite(&sprite);
}

void Gun::Update(Window *window, float timeDelta) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        SetPosition(-_speed * timeDelta, 0, true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        SetPosition(_speed * timeDelta, 0, true);
    }
    Object::Update(window, timeDelta);
}
