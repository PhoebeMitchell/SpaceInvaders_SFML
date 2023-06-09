//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/InvaderController.h"
#include "../headers/Constants.h"

const int ROW_COUNT = 5;
const int COLUMN_COUNT = 11;
const std::string INVADER_SPRITE_PATH = "./sprites/Invader1.png";
const int SPACING_X = 11 * Invader::INVADER_SCALE + 10;
const int SPACING_Y = 20;
const int START_POSITION_X = (WINDOW_WIDTH - (COLUMN_COUNT * SPACING_X + 10)) / 2;
const int START_POSITION_Y = 100;

InvaderController::InvaderController(Time *time, Window *window) : Updatable(time) {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            _invaders.push_back(std::make_unique<Invader>(GetTime(), window, INVADER_SPRITE_PATH));
            _invaders[i * COLUMN_COUNT + j]->SetPosition(START_POSITION_X + SPACING_X * j, START_POSITION_Y + SPACING_Y * i, false);
        }
    }
}

void InvaderController::Update() {
    for (int i = _invaders.size() - 1; i >= 0; i--) {
        if (!_invaders[i]->IsAlive()) {
            _invaders.erase(_invaders.begin() + i);
            continue;
        }

        _invaders[i]->Update();
    }
}
