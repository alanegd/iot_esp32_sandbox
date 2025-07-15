#include "AlterModeDevice.h"
#include <Arduino.h>

AlterModeDevice::AlterModeDevice(int ledPin, int blinkButtonPin, int toggleButtonPin) :
  ledActuator(ledPin, this),
  blinkModeButton(blinkButtonPin, BLINK_MODE_BUTTON_EVENT_ID, this),
  toggleOnOffButton(toggleButtonPin, TOGGLE_ON_OFF_BUTTON_EVENT_ID, this)
  {}

void AlterModeDevice::init() {

}

void AlterModeDevice::run() {
    blinkModeButton.check();
    toggleOnOffButton.check();
    ledActuator.update();
}

void AlterModeDevice::on(Event event) {
  if (event.id == BLINK_MODE_BUTTON_EVENT_ID) {
      Serial.println("Blink Mode Button Pressed. Handling BLINK_COMMAND.");
      ledActuator.handle(LedActuator::BLINK_COMMAND);
  } else if (event.id == TOGGLE_ON_OFF_BUTTON_EVENT_ID) {
      Serial.println("Toggle On/Off Button Pressed. Handling TOGGLE_COMMAND.");
      ledActuator.handle(LedActuator::TOGGLE_COMMAND);
  }
}

void AlterModeDevice::handle(Command command) {

}
