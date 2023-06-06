#include <iostream>
#include "headers/Window.h"
#include "headers/Game.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const std::string WINDOW_NAME = "Space Invaders";

int main() {
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    Game game(&window);
    game.Run();
    return 0;
}
