#pragma once
#include <Arduino.h>
#include "Timer.h"

class Led {
public:
  static constexpr uint8_t MIN_BRIGHT = 0;
  static constexpr uint8_t MIN_BRIGHT_LIGHT = 20;
  static constexpr uint8_t MAX_BRIGHT = 255;
  static constexpr int BRIGHT_STEP_AMOUNT = 30;
  static constexpr int STEP_AMOUNT_VALUE = 5;
  static constexpr int SPEED_AMOUNT = 10;
  static constexpr int MIN_SPEED = 80;
  static constexpr int MAX_SPEED = 10;

  explicit Led(uint8_t pin, long interval);
  void setup();

  void light();
  void fade();
  void disable();

  void speedUp();
  void speedDown();

  void brightUp();
  void brightDown();

private:
  uint8_t _pin;
  Timer _timer;
  bool _state = false;
  int _stepAmount = 5;
  long _speed;
  int _brightFade = 0;
  int _bright = MAX_BRIGHT;
  void updateBright();
};