#include "Controllers/LedController.h"
#include "Light/States/IState.h"

LedController::LedController(
    Button &enableButton
) :
_enableButton(enableButton)
{}

void LedController::setup(IState* currentState) {
    _currentState = currentState;
    _enableButton.setup();
}

void LedController::handle() {
    _enableButton.handle();

    if (_enableButton.wasPressed()) {
        IState* prev = _currentState;
        IState* next = _currentState->next();
        
        prev->exit();
        setState(next);
        _currentState->enter();
    }
    _currentState->tick();
}

void LedController::setState(IState* newState) {
    _currentState = newState;
}
