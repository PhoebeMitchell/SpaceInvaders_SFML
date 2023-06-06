//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

class Window;

class Game {
public:
    Game(Window *window);
    ~Game();

    void Run();
private:
    Window *_window;
};


#endif //SPACEINVADERS_GAME_H
