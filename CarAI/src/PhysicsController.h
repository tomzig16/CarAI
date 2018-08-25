#ifndef PHYSICSCONTROLLER_H
#define PHYSICSCONTROLLER_H

#include <vector>
#include "GameObject.h"

class PhysicsController
{
private:
    std::vector<GameObject*> m_moveableObjects;
public:
    PhysicsController();
    ~PhysicsController();
    void Update();
    void AddMoveableObject(GameObject*);
    void AddCollidingObject(GameObject*);

private:
    void MovementUpdate();
    void CollisionUpdate();
};

#endif // PHYSICSCONTROLLER_H
