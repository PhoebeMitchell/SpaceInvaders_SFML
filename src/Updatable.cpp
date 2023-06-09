//
// Created by Phoebe Mitchell on 07/06/2023.
//

#include "../headers/Updatable.h"

Updatable::Updatable(Time *time) {
    _time = time;
}

Time *Updatable::GetTime() {
    return _time;
}
