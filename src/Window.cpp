//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include <SFML/Window/Event.hpp>
#include "../headers/Window.h"

Window::Window(int width, int height, std::string name) : _renderWindow(sf::VideoMode(width, height), name) {

}

Window::~Window() {

}

bool Window::IsOpen() {
    return _renderWindow.isOpen();
}

void Window::PollEvents() {
    sf::Event event;
    while (_renderWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _renderWindow.close();
        }
    }
}

void Window::Clear() {
    _renderWindow.clear(_backgroundColor);
}

void Window::Display() {
    _renderWindow.display();
}
