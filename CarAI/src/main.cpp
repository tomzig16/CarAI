#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Renderer.h"
#include "PhysicsController.h"
#include "GameObject.h"
#include "InputHandler.h"

// Current InputHandler works only like that.
// TODO think of a way to pass parameters
GameObject gobject("Test Object");

void MoveNPC(GameObject &npcToMove)
{
    const int minX = 320;
    const int minY = 360;
    const int maxX = 960;
    static bool isMovingRight = true;
    int currentX = npcToMove.GetPosition().x;
    int currentY = npcToMove.GetPosition().y;
    if (currentX >= maxX)
    {
        isMovingRight = false;
    }
    if (currentX <= minX)
    {
        isMovingRight = true;
    }
    npcToMove.Move(Vector3(
        isMovingRight ? 0.5f : -0.5f,
        0.0f
    ));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Window");
    
    // Do other stuff here
    Renderer renderer(&window);
    PhysicsController physController;
    InputHandler inputHandler;

    GameObject secondObject("UncontrolledObject");
    secondObject.SetPosition(Vector3(0.0f, -360.0f));

    gobject.SetTexture("C:\\dev\\CarAI\\CarAI\\resources\\testtex.jpg");
    secondObject.SetTexture("C:\\dev\\CarAI\\CarAI\\resources\\testtex.jpg");

    renderer.AddObjectToRender(&gobject);
    renderer.AddObjectToRender(&secondObject);
    physController.AddMoveableObject(&gobject);
    physController.AddMoveableObject(&secondObject);
    inputHandler.AssignAction(Action::MOVE_UP, []() {    gobject.Move(Vector3( 0.0f,  0.5f)); });
    inputHandler.AssignAction(Action::MOVE_LEFT, []() {  gobject.Move(Vector3(-0.5f,  0.0f)); });
    inputHandler.AssignAction(Action::MOVE_DOWN, []() {  gobject.Move(Vector3( 0.0f, -0.5f)); });
    inputHandler.AssignAction(Action::MOVE_RIGHT, []() { gobject.Move(Vector3( 0.5f,  0.0f)); });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        MoveNPC(secondObject);
        inputHandler.HandleInputs();
        physController.Update();
        renderer.Draw();
    }

    printf("\n\nTHE PROGRAM IS CLOSING FROM MAIN\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
