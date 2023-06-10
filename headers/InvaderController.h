//
// Created by Phoebe Mitchell on 07/06/2023.
//

#ifndef SPACEINVADERS_INVADERCONTROLLER_H
#define SPACEINVADERS_INVADERCONTROLLER_H

#include "Object.h"
#include "Invader.h"
#include "Constants.h"

class Collision;

class InvaderController : public Updatable {
public:
    InvaderController(Time *time, Window *window, Collision *collision);

    void Update() override;
    void DecrementInvaderCount();
private:
    static const int PADDING = 15;
    static const int SPACING_X = 11 * Invader::INVADER_SCALE + PADDING;
    const int SPACING_Y = 20;
    const int START_POSITION_Y = 100;
    static const int ROW_COUNT = 5;
    static const int COLUMN_COUNT = 11;
    static const int START_POSITION_X = (WINDOW_WIDTH - (InvaderController::COLUMN_COUNT * SPACING_X + PADDING)) / 2;
    const std::string INVADER_SPRITE_PATH = "./sprites/Invader1.png";
    const float ROW_UPDATE_INTERVAL = 1;
    const float ROW_UPDATE_DELAY = 0.1f;
    const float INVADER_UPDATE_DELAY = 0.025f;
    const float INVADER_SPEED = 11;
    const float MAX_RIGHT_POSITION = WINDOW_WIDTH - 11;
    const float MAX_LEFT_POSITION = 20;

    Collision *_collision;
    int _currentDirection = 1;
    float _lastRowUpdateTime = 0;
    std::unique_ptr<Invader> _invaders[ROW_COUNT][COLUMN_COUNT];
    int _activeInvaderCount = 0;
    int _maxInvaderCount = 0;

    int GetFarthestRightInvaderPosition();
    int GetFarthestLeftInvaderPosition();
};


#endif //SPACEINVADERS_INVADERCONTROLLER_H
