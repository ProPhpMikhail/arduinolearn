#pragma once
#include <Arduino.h>
#include "Button/Button.h"
#include "Light/Led.h"
#include "Light/States/IState.h"
#include "Light/Led.h"
#include "Controllers/LedController.h"

class Light : public IState {
public:
    explicit Light(LedController& ledController, Led& led, Button& brightUpButton, Button& brightDownButton);
    void enter() override;
    void tick() override;
    void exit() override;

private:
    LedController& _ledController;
    Led& _led;
    Button& _brightUpButton;
    Button& _brightDownButton;
};