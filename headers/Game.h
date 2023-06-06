//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <vector>

class Window;
class Object;

class Game {
public:
    Game(Window *window);

    void Run();
    void AddObject(Object *object);
private:
    Window *_window;
    std::vector<Object*> _objects;
};

#endif //SPACEINVADERS_GAME_H
