#include "headers/Window.h"
#include "headers/Game.h"
#include "headers/Constants.h"
#include "headers/Gun.h"
#include "headers/InvaderController.h"

int main() {
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    Game game(&window);

    Gun gun(game.GetTime(), &window);
    game.AddUpdatable(&gun);

    InvaderController invaderController(game.GetTime(), &window);
    game.AddUpdatable(&invaderController);

    game.Run();
    return 0;
}
