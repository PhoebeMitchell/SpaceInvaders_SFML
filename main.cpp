#include <iostream>
#include "headers/Window.h"
#include "headers/Game.h"
#include "headers/Sprite.h"
#include "headers/Object.h"
#include "headers/Input.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const std::string WINDOW_NAME = "Space Invaders";

int main() {
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    Game game(&window);

    Sprite sprite("./sprites/Gun.png", 1, 5);
    sprite.SetOrigin(0.5f, 1.0f);
    sprite.SetPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
    Object object;
    object.SetSprite(&sprite);
    game.AddObject(&object);

    Input input;
    input.AddKeyFunction({sf::Keyboard::Left, [](){
        std::cout << "Hello" << std::endl;
    }});
    game.AddUpdatable(&input);

    game.Run();
    return 0;
}
