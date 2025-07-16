#include "MoistureControlDevice.h"
#include <Arduino.h>

MoistureControlDevice::MoistureControlDevice(
      int manualButtonPin, 
      int autoButtonPin,
      int relayPin,
      int soilSensorPin
    ) :
    manualModeButton(manualButtonPin, MANUAL_MODE_BUTTON_EVENT_ID, this),
    autoModeButton(autoButtonPin, AUTO_MODE_BUTTON_EVENT_ID, this),
    relayActuator(relayPin, this),
    soilSensorPin(soilSensorPin),
    currentMode(AUTO_MODE)
    {}

void MoistureControlDevice::init() {
  pinMode(soilSensorPin, INPUT);
  Serial.println("Moisture Control Device Initialized.");
}

void MoistureControlDevice::run() {
  manualModeButton.check();
  autoModeButton.check();

  if (currentMode == AUTO_MODE) {
    int sensorValue = digitalRead(soilSensorPin);
    if (sensorValue == HIGH) {
      // Si el sensor detecta humedad alta, enciende el relay.
      relayActuator.handle(RelayActuator::TURN_ON_COMMAND);
    } else {
      relayActuator.handle(RelayActuator::TURN_OFF_COMMAND);
    }
  }
}

void MoistureControlDevice::handle(Command command) {

}

void MoistureControlDevice::on(Event event) {
    if (event.id == MANUAL_MODE_BUTTON_EVENT_ID) {
      if (currentMode == MANUAL_MODE) {
        Serial.println("Toggling Relay in Manual Mode.");
        relayActuator.handle(RelayActuator::TOGGLE_COMMAND);
      } else {
        currentMode = MANUAL_MODE;
        Serial.println("Switched to MANUAL_MODE.");
      }
  } else if (event.id == AUTO_MODE_BUTTON_EVENT_ID) {
      currentMode = AUTO_MODE;
      Serial.println("Switched to AUTO_MODE.");
  }
}

