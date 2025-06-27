#include "AmbientDisplayDevice.h"
#include <Arduino.h>

AmbientDisplayDevice::AmbientDisplayDevice(uint8_t dhtPin, uint8_t lcdAddress) : 
    dhtSensor(dhtPin, DHT22, this),
    lcdDisplay(lcdAddress, 16, 2) {}

void AmbientDisplayDevice::init() {
    Serial.begin(115200);
    Serial.println("=========================================");
    Serial.println("Ambient Temperature & Humidity Display");
    Serial.println("=========================================");

    dhtSensor.begin();
    lcdDisplay.init();
    lcdDisplay.displayData(0.0, 0.0);
}

void AmbientDisplayDevice::run() {
    dhtSensor.check();
}

void AmbientDisplayDevice::on(Event event) {
    if (event == DhtSensor::DATA_UPDATED_EVENT) {
        Serial.println("Sensor data updated. Updating display.");
        updateDisplay();
    }
}

void AmbientDisplayDevice::handle(Command command) {
    // This device does not handle any commands, so we leave this empty.
}

void AmbientDisplayDevice::updateDisplay() {
    // Get the latest data from the sensor
    float temp = dhtSensor.temperature;
    float hum = dhtSensor.humidity;

    Serial.printf("Temperature: %.1f C, Humidity: %.1f %%\n", temp, hum);
  
    lcdDisplay.displayData(temp, hum);
}