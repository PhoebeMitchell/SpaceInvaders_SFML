//
// Created by Phoebe Mitchell on 07/06/2023.
//

#ifndef SPACEINVADERS_INVADERCONTROLLER_H
#define SPACEINVADERS_INVADERCONTROLLER_H

#include "Object.h"
#include "Invader.h"

class InvaderController : public Updatable {
public:
    InvaderController(Window *window);

    InvaderController(Time *time, Window *window);

    void Update() override;
private:
    std::vector<std::unique_ptr<Invader>> _invaders;
};


#endif //SPACEINVADERS_INVADERCONTROLLER_H
