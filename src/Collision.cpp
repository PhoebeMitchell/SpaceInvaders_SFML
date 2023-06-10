//
// Created by Phoebe Mitchell on 10/06/2023.
//

#include "../headers/Collision.h"
#include "../headers/Object.h"

Object *Collision::GetCollidingObject(Object *object) {
    auto sourceBounds = object->GetSprite()->GetBounds();
    for (auto targetObject : _objects) {
        if (targetObject != object && targetObject->IsCollisionActive() && sourceBounds.intersects(targetObject->GetSprite()->GetBounds())) {
            return targetObject;
        }
    }
    return nullptr;
}

void Collision::AddObject(Object *object) {
    _objects.push_back(object);
}
