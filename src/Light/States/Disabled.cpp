#include "Light/States/IState.h"
#include "Light/States/Disabled.h"

Disabled::Disabled(
    LedController& ledController, Led& led
) :
_ledController(ledController),
_led(led)
{}

void Disabled::enter() {
    _led.disable();
}

void Disabled::tick() {
    
}

void Disabled::exit() {
     
}
