#include "Light/Led.h"

Led::Led(uint8_t pin, long interval) : _pin(pin), _timer(interval), _speed(interval) {}

void Led::setup() {
    pinMode(_pin, OUTPUT);
}

void Led::disable() {
    analogWrite(_pin, MIN_BRIGHT);
}

void Led::light() {
    analogWrite(_pin, _bright);
}

void Led::fade() {
    if (!_timer.isReady()) return;
    analogWrite(_pin, _brightFade);
    updateBright();
}

void Led::updateBright() {
    _brightFade += _stepAmount;
    if (_brightFade <= MIN_BRIGHT) {
        _brightFade = MIN_BRIGHT;
        _stepAmount = abs(_stepAmount);
    }

    if (_brightFade >= MAX_BRIGHT) {
        _brightFade = MAX_BRIGHT;
        _stepAmount = -abs(_stepAmount);
    }
}

void Led::speedUp() {
    if (_speed <= MAX_SPEED) return;
    _speed -= SPEED_AMOUNT;
    _timer.setInterval(_speed);
    _timer.reset();
}

void Led::speedDown() {
    if (_speed >= MIN_SPEED) return;
    _speed += SPEED_AMOUNT;
    _timer.setInterval(_speed);
    _timer.reset();
}

void Led::brightUp() {
    int newBright = _bright;
    newBright += BRIGHT_STEP_AMOUNT;
    if (newBright > MAX_BRIGHT) newBright = MAX_BRIGHT;
    _bright = newBright;
}

void Led::brightDown() {
    int newBright = _bright;
    newBright -= BRIGHT_STEP_AMOUNT;
    if (newBright < MIN_BRIGHT_LIGHT) newBright = MIN_BRIGHT_LIGHT;
    _bright = newBright;
}
