//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/InvaderController.h"
#include "../headers/Collision.h"

InvaderController::InvaderController(Time *time, Window *window, Collision *playerCollision, Collision *invaderCollision) : Updatable(time) {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            _invaders[i][j] = std::make_unique<Invader>(GetTime(), window, INVADER_SPRITE_PATH, this, playerCollision, invaderCollision);
            _invaders[i][j]->SetPosition(START_POSITION_X + SPACING_X * j, START_POSITION_Y + SPACING_Y * i, false);
            invaderCollision->AddObject(_invaders[i][j].get());
            _activeInvaderCount++;
            if (i == ROW_COUNT - 1) {
                _invaders[i][j]->SetCanShoot(true);
            }
        }
    }
    _maxInvaderCount = _activeInvaderCount;
}

void InvaderController::Update() {
    auto currentTime = GetTime()->GetCurrentTime();

    float multiplier = ((float)_activeInvaderCount / _maxInvaderCount);
    if (currentTime - _lastRowUpdateTime  > ROW_UPDATE_INTERVAL * multiplier) {
        _lastRowUpdateTime = currentTime;
        if (GetFarthestRightInvaderPosition() + _invaders[0][0]->GetSize().x > MAX_RIGHT_POSITION && _currentDirection > 0 ||
            GetFarthestLeftInvaderPosition() < MAX_LEFT_POSITION && _currentDirection < 0) {
            for (int i = 0; i < ROW_COUNT; i++) {
                for (int j = 0; j < COLUMN_COUNT; j++) {
                    _invaders[ROW_COUNT - i - 1][j]->MoveAfterDelay(0, INVADER_SPEED, INVADER_UPDATE_DELAY * (i * ROW_COUNT + j) * multiplier);
                }
            }
            _currentDirection *= -1;
        } else {
            for (int i = 0; i < ROW_COUNT; i++) {
                for (int j = 0; j < COLUMN_COUNT; j++) {
                    _invaders[ROW_COUNT - i - 1][j]->MoveAfterDelay(INVADER_SPEED * _currentDirection, 0, ROW_UPDATE_DELAY * i * multiplier);
                }
            }
        }
    }

    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            if (!_invaders[i][j]->IsAlive()) {
                continue;
            }

            _invaders[i][j]->Update();
        }
    }
}

int InvaderController::GetFarthestRightInvaderPosition() {
    int farthestPosition = 0;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = COLUMN_COUNT - 1; j >= 0; j--) {
            if (_invaders[i][j]->IsAlive()) {
                auto position = _invaders[i][j]->GetPosition().x;
                if (position > farthestPosition) {
                    farthestPosition = position;
                }
                continue;
            }
        }
    }
    return farthestPosition;
}

int InvaderController::GetFarthestLeftInvaderPosition() {
    int farthestPosition = INT_MAX;
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            if (_invaders[i][j]->IsAlive()) {
                auto position = _invaders[i][j]->GetPosition().x;
                if (position < farthestPosition) {
                    farthestPosition = position;
                }
            }
            continue;
        }
    }
    return farthestPosition;
}

void InvaderController::DecrementInvaderCount() {
    _activeInvaderCount--;
}
