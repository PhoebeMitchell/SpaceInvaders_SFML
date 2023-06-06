#include "headers/Window.h"
#include "headers/Game.h"
#include "headers/Sprite.h"
#include "headers/Object.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const std::string WINDOW_NAME = "Space Invaders";

int main() {
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    Game game(&window);

    Sprite sprite("./sprites/Invader1.png", 2);
    Object object;
    object.SetSprite(&sprite);
    game.AddObject(&object);

    game.Run();
    return 0;
}
