//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_TIME_H
#define SPACEINVADERS_TIME_H


#include <SFML/System/Clock.hpp>

class Time {
public:
    float Update();
    float GetTimeDelta();
    float GetCurrentTime();
private:
    sf::Clock _clock;
    float _currentTime;
    float _timeDelta;
};


#endif //SPACEINVADERS_TIME_H
