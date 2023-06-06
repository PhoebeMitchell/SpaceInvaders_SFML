//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_INPUT_H
#define SPACEINVADERS_INPUT_H

#include "Updatable.h"
#include "KeyFunction.h"

class Input : public Updatable {
public:
    void Update(float timeDelta) override;

    void AddKeyFunction(KeyFunction keyFunction);
private:
    std::vector<KeyFunction> _keyFunctions;
};


#endif //SPACEINVADERS_INPUT_H
