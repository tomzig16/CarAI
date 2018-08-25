#include "PhysicsController.h"

PhysicsController::PhysicsController()
{

}

PhysicsController::~PhysicsController()
{

}

void PhysicsController::AddMoveableObject(GameObject* objToAdd)
{
    m_moveableObjects.push_back(objToAdd);
}

void PhysicsController::AddCollidingObject(GameObject* objToAdd)
{

}


void PhysicsController::Update()
{
    MovementUpdate();
    CollisionUpdate();
}

void PhysicsController::MovementUpdate()
{
    for (int i = 0; i < m_moveableObjects.size(); i++)
    {
        sf::Sprite* objectSprite = m_moveableObjects[i]->GetSpritePtr();
        Vector3 newPosition = m_moveableObjects[i]->GetPosition();
        objectSprite->setPosition(newPosition.x, newPosition.y);
    }
}

void PhysicsController::CollisionUpdate()
{

}

