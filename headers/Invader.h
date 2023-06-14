//
// Created by Phoebe Mitchell on 07/06/2023.
//

#ifndef SPACEINVADERS_INVADER_H
#define SPACEINVADERS_INVADER_H

#include <SFML/System/Vector2.hpp>
#include "Object.h"
#include "Bullet.h"
#include "Destroyable.h"

class InvaderController;

class Invader : public Object, public Destroyable {
public:
    Invader(Time *time, Window *window, std::string spritePath, InvaderController *invaderController,
            Collision *playerCollision, Collision *invaderCollision, int rowNumber, int columnNumber);

    static const int INVADER_SCALE = 2;

    void Update() override;
    bool IsAlive();
    void IncrementSprite();
    void MoveAfterDelay(float x, float y, float delay);
    void SetCanShoot(bool canShoot);
    void Destroy() override;
private:
    const float MIN_SHOOT_DELAY = 0.5f;
    const float MAX_SHOOT_DELAY = 10;
    const sf::Vector2f BULLET_VELOCITY = {0, 400};

    InvaderController *_invaderController;
    Collision *_playerCollision;
    Collision *_invaderCollision;
    bool _shouldMoveAfterDelay = false;
    float _moveAfterDelayCallTime = 0;
    float _xDirection = 0;
    float _yDirection = 0;
    float _moveDelay = 0;
    bool _isAlive = 1;
    bool _canShoot = false;
    float _nextShootTime = 0;
    std::vector<std::unique_ptr<Bullet>> _bullets;
    int _columnNumber;
    int _rowNumber;

    void CalculateNextShootTime(Time *time);
    void Shoot();
};


#endif //SPACEINVADERS_INVADER_H
