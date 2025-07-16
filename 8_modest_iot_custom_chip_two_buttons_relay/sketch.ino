#include "MoistureControlDevice.h"

const int MANUAL_BUTTON_PIN = 8;
const int AUTO_BUTTON_PIN = 10;
const int RELAY_PIN = 13;
const int CAPACITIVE_MOISTURE_PIN = 2;

MoistureControlDevice device(MANUAL_BUTTON_PIN, AUTO_BUTTON_PIN, RELAY_PIN, CAPACITIVE_MOISTURE_PIN);

void setup() {
  Serial.begin(115200);
  device.init();
}

void loop() {
  device.run();
  delay(10);
}
