//
// Created by Phoebe Mitchell on 10/06/2023.
//

#ifndef SPACEINVADERS_COLLISION_H
#define SPACEINVADERS_COLLISION_H


#include <vector>

class Object;

class Collision {
public:
    Object *GetCollidingObject(Object *object);
    void AddObject(Object *object);
private:
    std::vector<Object*> _objects;
};


#endif //SPACEINVADERS_COLLISION_H
