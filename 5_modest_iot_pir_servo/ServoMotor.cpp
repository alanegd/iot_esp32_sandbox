#include "ServoMotor.h"
#include <Arduino.h>

/**
 * @file ServoMotor.cpp
 * @brief Implements the ServoMotor class.
 */
const Command ServoMotor::OPEN_COMMAND = Command(OPEN_COMMAND_ID);
const Command ServoMotor::CLOSE_COMMAND = Command(CLOSE_COMMAND_ID);

ServoMotor::ServoMotor(int pin, CommandHandler* commandHandler)
    : Actuator(pin, commandHandler), currentAngle(OPEN_ANGLE) {}

void ServoMotor::attach() {
    servo.attach(pin);
    servo.write(currentAngle); // Start at initial position
}

void ServoMotor::handle(Command command) {
    if (command == OPEN_COMMAND) {
        currentAngle = OPEN_ANGLE;
        Serial.println("Command received: OPEN_COMMAND. Moving servo to 0 degrees.");
    } else if (command == CLOSE_COMMAND) {
        currentAngle = CLOSED_ANGLE;
        Serial.println("Command received: CLOSE_COMMAND. Moving servo to 90 degrees.");
    }
    servo.write(currentAngle);
    Actuator::handle(command);
}

int ServoMotor::getCurrentAngle() const {
    return currentAngle;
}