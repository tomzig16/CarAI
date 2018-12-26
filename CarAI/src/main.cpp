#include <SFML/Graphics.hpp>
#include <iostream>

#include "Renderer.h"
#include "PhysicsController.h"
#include "GameObject.h"
#include "InputHandler.h"

// Current InputHandler works only like that.
// TODO think of a way to pass parameters
GameObject gobject("Test Object");

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Window");
    
    // Do other stuff here
    Renderer renderer(&window);
    PhysicsController physController;
    InputHandler inputHandler;


    gobject.SetTexture("C:\\dev\\CarAI\\CarAI\\resources\\testtex.jpg");

    renderer.AddObjectToRender(&gobject);
    physController.AddMoveableObject(&gobject); 
    inputHandler.AssignAction(Action::MOVE_UP, []() {    gobject.Move(Vector3( 0.0f,  0.5f)); });
    inputHandler.AssignAction(Action::MOVE_LEFT, []() {  gobject.Move(Vector3(-0.5f,  0.0f)); });
    inputHandler.AssignAction(Action::MOVE_DOWN, []() {  gobject.Move(Vector3( 0.0f, -0.5f)); });
    inputHandler.AssignAction(Action::MOVE_RIGHT, []() { gobject.Move(Vector3( 0.5f,  0.0f)); });

    // Main loop
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
        inputHandler.HandleInputs();
        physController.Update();
        renderer.Draw();
    }

    printf("\n\nPROGRAM IS CLOSING FROM MAIN\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
