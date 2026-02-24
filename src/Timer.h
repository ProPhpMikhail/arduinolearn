#pragma once
#include <Arduino.h>

class Timer {
public:
  explicit Timer(unsigned long interval)
    : _interval(interval), _last(0) {}

  inline bool isReady() {
    unsigned long now = millis();
    if (now - _last >= _interval) {
      _last = now;
      return true;
    }
    return false;
  }

  inline void reset() {
    _last = millis();
  }

  inline void setInterval(long interval)
  {
    _interval = interval;
  }

private:
  unsigned long _interval;
  unsigned long _last;
};