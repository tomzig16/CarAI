#include "InputHandler.h"

#include <SFML/Window.hpp>

void ActionFallback()
{
    // This function is called when button with no assigned action is called. 
    // TODO handle this properly
}

InputHandler::InputHandler()
{
    for (int i = 0; i < nOfInputs; i++)
    {
        ActionMethod[i] = &ActionFallback;
    }
}

InputHandler::~InputHandler()
{

}

void InputHandler::AssignAction(Action action, void(*fToExecute)())
{
    InputHandler::ActionMethod[action] = fToExecute;
}

void InputHandler::HandleInputs()
{
    using namespace sf;
    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
        ActionMethod[Action::MOVE_UP]();
    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
        ActionMethod[Action::MOVE_LEFT]();
    if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
        ActionMethod[Action::MOVE_DOWN]();
    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
        ActionMethod[Action::MOVE_RIGHT]();

}