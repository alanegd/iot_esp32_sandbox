#include "ValveActuator.h"
#include <Arduino.h>

const Command ValveActuator::OPEN_VALVE_COMMAND = Command(ValveActuator::OPEN_VALVE_COMMAND_ID);
const Command ValveActuator::CLOSE_VALVE_COMMAND = Command(ValveActuator::CLOSE_VALVE_COMMAND_ID);

ValveActuator::ValveActuator(int pin, CommandHandler* commandHandler)
    : Actuator(pin, commandHandler), stateOpen(false) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void ValveActuator::handle(Command command) {
    // Check if the state needs to be changed
    if (command == OPEN_VALVE_COMMAND && !stateOpen) {
        stateOpen = true;
        digitalWrite(pin, HIGH);
    } else if (command == CLOSE_VALVE_COMMAND && stateOpen) {
        stateOpen = false;
        digitalWrite(pin, LOW);
    }
}

bool ValveActuator::isOpen() const {
    return stateOpen;
}