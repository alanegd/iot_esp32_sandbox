#include "IrrigationDevice.h"

const uint8_t DHT_PIN = 13;
const uint8_t VALVE_PIN = 16;

IrrigationDevice device(DHT_PIN, VALVE_PIN);

const unsigned long SENSOR_READ_INTERVAL = 2000;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("\n=========================================");
  Serial.println("    Smart Irrigation Device         ");
  Serial.println("=========================================");
  device.init();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= SENSOR_READ_INTERVAL) {
    previousMillis = currentMillis;
    device.run();
  }
}