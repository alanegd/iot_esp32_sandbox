#include "AlterModeDevice.h"

const int LED_PIN = 1;
const int BLINK_MODE_BUTTON_PIN = 8;
const int TOGGLE_ON_OFF_BUTTON_PIN = 10;

AlterModeDevice device(LED_PIN, BLINK_MODE_BUTTON_PIN, TOGGLE_ON_OFF_BUTTON_PIN);

void setup() {
  Serial.begin(115200);
  device.init();
}

void loop() {
  device.run();
  delay(10);
}
