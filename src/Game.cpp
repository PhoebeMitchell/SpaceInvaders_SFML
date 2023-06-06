//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Game.h"
#include "../headers/Window.h"
#include "../headers/Object.h"
#include "../headers/Updatable.h"

Game::Game(Window *window) {
    _window = window;
}

void Game::Run() {
    while (_window->IsOpen()) {
        _window->PollEvents();
        _window->Clear();

        for (auto updatable : _updatables) {
            updatable->Update(0);
        }

        for (auto object : _objects) {
            object->Update(_window);
        }

        _window->Display();
    }
}

void Game::AddObject(Object *object) {
    _objects.push_back(object);
}

void Game::AddUpdatable(Updatable *updatable) {
    _updatables.push_back(updatable);
}
