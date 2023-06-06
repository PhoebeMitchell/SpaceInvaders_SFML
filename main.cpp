#include "headers/Window.h"
#include "headers/Game.h"
#include "headers/Sprite.h"
#include "headers/Object.h"
#include "headers/Constants.h"
#include "headers/Gun.h"

int main() {
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    Game game(&window);

    Gun gun(&game);

    game.Run();
    return 0;
}
