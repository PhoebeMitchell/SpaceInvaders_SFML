//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_KEYFUNCTION_H
#define SPACEINVADERS_KEYFUNCTION_H

#include <SFML/Window/Keyboard.hpp>
#include <functional>

struct KeyFunction {
    sf::Keyboard::Key key;
    std::function<void()> function;
};

#endif //SPACEINVADERS_KEYFUNCTION_H
