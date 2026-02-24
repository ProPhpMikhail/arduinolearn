#pragma once
#include <Arduino.h>
#include "Button/Button.h"
#include "Light/Led.h"
#include "Light/States/IState.h"
#include "Light/Led.h"
#include "Controllers/LedController.h"

class Disabled : public IState {
public:
    explicit Disabled(LedController& ledController, Led& led);
    void enter() override;
    void tick() override;
    void exit() override;

private:
    LedController& _ledController;
    Led& _led;
};