//
// Created by Phoebe Mitchell on 06/06/2023.
//

#ifndef SPACEINVADERS_OBJECT_H
#define SPACEINVADERS_OBJECT_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Game.h"
#include "Updatable.h"
#include "Time.h"

class Window;

class Object : public Updatable {
public:
    Object(Time *time, Window *window);
    void Update() override;
    void SetPosition(float x, float y, bool relative);
    sf::Vector2f GetSize();
    sf::Vector2f GetPosition();
    Sprite *LoadSprite(std::string spritePath);
    Sprite *GetSprite();
    Window *GetWindow();
    bool IsCollisionActive();
    void SetCollisionActive(bool isCollisionActive);
private:
    Window *_window;
    bool _isCollisionActive = true;
    std::unique_ptr<Sprite> _sprite;
};


#endif //SPACEINVADERS_OBJECT_H
