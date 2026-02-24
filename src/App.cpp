#include "App.h"
#include "Light/Led.h"
#include "Button/Button.h"
#include "Controllers/LedController.h"
#include "Light/States/IState.h"
#include "Light/States/Fade.h"
#include "Light/States/Disabled.h"
#include "Light/States/Light.h"

Led led(9, 40);
Button enabledButton(2, 20);
Button upButton(7, 20);
Button downButton(4, 20);
LedController ledController(enabledButton);

Light lightState(ledController, led, upButton, downButton);
Fade fadeState(ledController, led, upButton, downButton);
Disabled disabledState(ledController, led);

void App::setup() {
  Serial.begin(9600);
  led.setup();
  upButton.setup();
  downButton.setup();

  lightState.setNext(&fadeState);
  fadeState.setNext(&disabledState);
  disabledState.setNext(&lightState);

  ledController.setup(&disabledState);
}

void App::loop() {
  ledController.handle();
}