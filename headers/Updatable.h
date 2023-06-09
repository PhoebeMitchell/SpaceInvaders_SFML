//
// Created by Phoebe Mitchell on 07/06/2023.
//

#ifndef SPACEINVADERS_UPDATABLE_H
#define SPACEINVADERS_UPDATABLE_H

#include "Time.h"

class Updatable {
public:
    Updatable(Time *time);
    virtual void Update() = 0;
    Time *GetTime();
private:
    Time *_time;
};

#endif //SPACEINVADERS_UPDATABLE_H
