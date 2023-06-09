//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <vector>
#include "Time.h"

class Window;
class Object;
class Updatable;

class Game {
public:
    Game(Window *window);

    void Run();
    void AddUpdatable(Updatable *updatable);
    Time *GetTime();
private:
    Window *_window;
    std::vector<Updatable*> _updatables;
    Time _time;
};

#endif //SPACEINVADERS_GAME_H
