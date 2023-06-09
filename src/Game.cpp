//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Game.h"
#include "../headers/Window.h"
#include "../headers/Object.h"

Game::Game(Window *window) {
    _window = window;
}

void Game::Run() {
    while (_window->IsOpen()) {
        _window->PollEvents();
        _window->Clear();

        _time.Update();

        for (auto updatable: _updatables) {
            updatable->Update();
        }

        _window->Display();
    }
}

void Game::AddUpdatable(Updatable *updatable) {
    _updatables.push_back(updatable);
}

Time *Game::GetTime() {
    return &_time;
}
