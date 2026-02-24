#include "Button/Button.h"

Button::Button(uint8_t pin, long debaounceInterval = 30) :
_pin(pin),
_timer(debaounceInterval)
{}

void Button::setup() {
    pinMode(_pin, INPUT_PULLUP);
}

void Button::handle() {
    bool reading = digitalRead(_pin);

    if (reading != _prevReading) {
        _timer.reset();
    }

    if (_timer.isReady()) {
        if (reading != _stableState) {
            _stableState = reading;

            if (_stableState == LOW) {
                _pressed = true;
            }
        }
    }

    _prevReading = reading;
}

bool Button::wasPressed() {
    bool result = _pressed;
    _pressed = false;
    return result;
}
