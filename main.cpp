#include "headers/Window.h"
#include "headers/Game.h"
#include "headers/Constants.h"
#include "headers/Gun.h"
#include "headers/InvaderController.h"
#include "headers/Collision.h"

int main() {
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    Game game(&window);

    Collision collision;

    Gun gun(game.GetTime(), &window, &collision);
    game.AddUpdatable(&gun);

    InvaderController invaderController(game.GetTime(), &window, &collision);
    game.AddUpdatable(&invaderController);

    game.Run();
    return 0;
}
