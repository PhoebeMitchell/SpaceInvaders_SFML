//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Time.h"

float Time::GetTimeDelta() {
    float time = _clock.getElapsedTime().asSeconds();
    float deltaTime = time - _previousTime;
    _previousTime = time;
    return deltaTime;
}
