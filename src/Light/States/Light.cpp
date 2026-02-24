#include "Light/States/IState.h"
#include "Light/States/Light.h"
#include "Button/Button.h"

Light::Light(
    LedController& ledController, Led& led,
    Button& brightUpButton, Button& brightDownButton
) :
_ledController(ledController),
_led(led),
_brightUpButton(brightUpButton),
_brightDownButton(brightDownButton)
{}

void Light::enter() {
    _led.disable();
}

void Light::tick() {
    _led.light();
    _brightUpButton.handle();
    _brightDownButton.handle();
    if (_brightUpButton.wasPressed()) {
        _led.brightUp();
    }

    if (_brightDownButton.wasPressed()) {
        _led.brightDown();
    }
}

void Light::exit() {
    _led.disable();
}
