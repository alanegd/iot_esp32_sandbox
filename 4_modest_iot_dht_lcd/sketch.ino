#include "AmbientDisplayDevice.h"


const uint8_t DHT_PIN = 13;
const uint8_t LCD_ADDRESS = 0x27;

AmbientDisplayDevice device(DHT_PIN, LCD_ADDRESS);

const unsigned long SENSOR_READ_INTERVAL = 5000; // 5 seconds
unsigned long previousMillis = 0;

void setup() {
  device.init();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= SENSOR_READ_INTERVAL) {
    previousMillis = currentMillis;
    device.run();
  }
}
