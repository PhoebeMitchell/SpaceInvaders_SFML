//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_WINDOW_H
#define SPACEINVADERS_WINDOW_H

#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window(int width, int height, std::string name);

    bool IsOpen();
    void PollEvents();
    void Clear();
    void Draw(sf::Drawable *drawable);
    void Display();
private:
    sf::RenderWindow _renderWindow;
    sf::Color _backgroundColor = sf::Color::Black;
};

#endif //SPACEINVADERS_WINDOW_H
