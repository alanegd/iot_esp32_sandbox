#include "RelayActuator.h"
#include <Arduino.h>

const Command RelayActuator::TURN_ON_COMMAND = Command(RelayActuator::TURN_ON_COMMAND_ID);
const Command RelayActuator::TURN_OFF_COMMAND = Command(RelayActuator::TURN_OFF_COMMAND_ID);
const Command RelayActuator::TOGGLE_COMMAND = Command(RelayActuator::TOGGLE_COMMAND_ID);


RelayActuator::RelayActuator(int pin, CommandHandler* commandHandler) :
  Actuator(pin, commandHandler),
  stateOn(false)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

void RelayActuator::handle(Command command) {
  if (command == TURN_ON_COMMAND && !stateOn) {
    stateOn = true;
    digitalWrite(pin, HIGH);
    Serial.println("Relay turned ON");
  } else if (command == TURN_OFF_COMMAND && stateOn) {
    stateOn = false;
    digitalWrite(pin, LOW);
    Serial.println("Relay turned OFF");
  } else if (command == TOGGLE_COMMAND) {
    stateOn = !stateOn;
    digitalWrite(pin, stateOn);
    Serial.print("Relay toggled to: ");
    Serial.println(stateOn ? "ON" : "OFF");
  }
}

bool RelayActuator::isOn() const {
  return stateOn;
}