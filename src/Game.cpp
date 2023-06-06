//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Game.h"
#include "../headers/Window.h"
#include "../headers/Object.h"
#include "../headers/Time.h"

Game::Game(Window *window) {
    _window = window;
}

void Game::Run() {
    Time time;
    while (_window->IsOpen()) {
        _window->PollEvents();
        _window->Clear();

        float deltaTime = time.GetTimeDelta();

        for (auto object : _objects) {
            object->Update(_window, deltaTime);
        }

        _window->Display();
    }
}

void Game::AddObject(Object *object) {
    _objects.push_back(object);
}
