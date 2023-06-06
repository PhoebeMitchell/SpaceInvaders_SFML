//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <vector>

class Window;
class Object;
class Updatable;

class Game {
public:
    Game(Window *window);

    void Run();
    void AddObject(Object *object);
    void AddUpdatable(Updatable *updatable);
private:
    Window *_window;
    std::vector<Object*> _objects;
    std::vector<Updatable*> _updatables;
};

#endif //SPACEINVADERS_GAME_H
