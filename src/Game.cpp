//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Game.h"
#include "../headers/Window.h"

Game::Game(Window *window) {
    _window = window;
}

Game::~Game() {

}

void Game::Run() {
    while (_window->IsOpen()) {
        _window->PollEvents();
        _window->Clear();
        _window->Display();
    }
}
