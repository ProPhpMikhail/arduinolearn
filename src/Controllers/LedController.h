#pragma once
#include <Arduino.h>
#include "Button/Button.h"
#include "Light/Led.h"
#include "Light/States/IState.h"

class LedController {
public:
    explicit LedController(Button& enableButton);
    void setup(IState* currentState);
    void handle();
    void setState(IState* newState);

private:
    IState* _currentState = nullptr;
    Button& _enableButton;
};