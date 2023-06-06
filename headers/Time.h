//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_TIME_H
#define SPACEINVADERS_TIME_H


#include <SFML/System/Clock.hpp>

class Time {
public:
    float GetTimeDelta();
private:
    sf::Clock _clock;
    float _previousTime;
};


#endif //SPACEINVADERS_TIME_H
