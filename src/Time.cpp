//
// Created by Phoebe Mitchell on 06/06/2023.
//

#include "../headers/Time.h"

float Time::GetTimeDelta() {
    return _timeDelta;
}

float Time::Update() {
    auto newTime =_clock.getElapsedTime().asSeconds();
    _timeDelta = newTime - _currentTime;
    _currentTime = newTime;
}

float Time::GetCurrentTime() {
    return _currentTime;
}
