#pragma once
#include <Arduino.h>
#include "Timer.h"

class Button {
public:
    explicit Button(uint8_t pin, long debaounceInterval);
    void setup();
    void handle();
    bool wasPressed();

private:
    uint8_t _pin;
    Timer _timer;
    bool _prevReading = HIGH;
    bool _stableState = HIGH;
    bool _pressed = false;
};