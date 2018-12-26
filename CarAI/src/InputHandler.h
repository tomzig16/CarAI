#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

enum Action
{
    MOVE_UP = 0,
    MOVE_DOWN = 1,
    MOVE_LEFT = 2,
    MOVE_RIGHT = 3,
};
const int nOfInputs = 4;

class InputHandler
{
private:
    void(*ActionMethod[nOfInputs])();
public:
    InputHandler();
    ~InputHandler();

    void AssignAction(Action action, void(*fToExecute)());
    void HandleInputs();
};

#endif // !INPUT_HANDLER_H
