//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include <SFML/Window.hpp>
#include "../headers/Input.h"

void Input::Update(float timeDelta) {
    for (auto keyFunction : _keyFunctions) {
        if (sf::Keyboard::isKeyPressed(keyFunction.key)) {
            keyFunction.function();
        }
    }
}

void Input::AddKeyFunction(KeyFunction keyFunction) {
    _keyFunctions.push_back(keyFunction);
}
