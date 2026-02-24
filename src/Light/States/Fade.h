#pragma once
#include <Arduino.h>
#include "Button/Button.h"
#include "Light/Led.h"
#include "Light/States/IState.h"
#include "Light/Led.h"
#include "Controllers/LedController.h"

class Fade : public IState {
public:
    explicit Fade(LedController& ledController, Led& led, Button& speedUpButton, Button& speedDownButton);
    void enter() override;
    void tick() override;
    void exit() override;

private:
    LedController& _ledController;
    Led& _led;
    Button& _speedUpButton;
    Button& _speedDownButton;
};