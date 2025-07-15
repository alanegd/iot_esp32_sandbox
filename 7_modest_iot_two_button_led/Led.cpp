#include "Led.h"
#include <Arduino.h>

const Command LedActuator::TOGGLE_COMMAND = Command(TOGGLE_COMMAND_ID);
const Command LedActuator::BLINK_COMMAND = Command(BLINK_COMMAND_ID);
const Command LedActuator::TURN_OFF_COMMAND = Command(TURN_OFF_COMMAND_ID);

LedActuator::LedActuator(int pin, CommandHandler* commandHandler) :
    Actuator(pin, commandHandler),
    stateOn(false),
    blinking(false),
    lastBlinkTime(0) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void LedActuator::handle(Command command) {
    if (command.id == TOGGLE_COMMAND_ID) {
        blinking = false;
        toggleState();
    } else if (command.id == BLINK_COMMAND_ID) {
        blinking = !blinking;
        if (!blinking) {
            turnOff();
        }
    } else if (command.id == TURN_OFF_COMMAND_ID) {
        blinking = false;
        turnOff();
    }
}

void LedActuator::update() {
    if (blinking && (millis() - lastBlinkTime >= BLINK_INTERVAL)) {
        lastBlinkTime = millis();
        toggleState();
    }
}

void LedActuator::turnOn() {
    stateOn = true;
    digitalWrite(pin, HIGH);
    Serial.println("LED state: ON");
}

void LedActuator::turnOff() {
    stateOn = false;
    digitalWrite(pin, LOW);
    Serial.println("LED state: OFF");
}

void LedActuator::toggleState() {
    stateOn ? turnOff() : turnOn();
}