#include "Light/States/IState.h"
#include "Light/States/Fade.h"
#include "Button/Button.h"

Fade::Fade(
    LedController& ledController, Led& led,
    Button& speedUpButton, Button& speedDownButton
) :
_ledController(ledController),
_led(led),
_speedUpButton(speedUpButton),
_speedDownButton(speedDownButton)
{}

void Fade::enter() {
    _led.disable();
}

void Fade::tick() {
    _led.fade();
    _speedUpButton.handle();
    _speedDownButton.handle();
    if (_speedUpButton.wasPressed()) {
        _led.speedUp();
    }

    if (_speedDownButton.wasPressed()) {
        _led.speedDown();
    }
}

void Fade::exit() {
    _led.disable();
}
