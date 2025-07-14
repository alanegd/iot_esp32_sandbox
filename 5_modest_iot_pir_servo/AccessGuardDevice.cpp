#include "AccessGuardDevice.h"
#include <Arduino.h>

/**
 * @file AccessGuardDevice.cpp
 * @brief Implements the main device logic for the AccessGuard project.
 * Includes a non-blocking delay to wait for sensor stabilization.
 */
AccessGuardDevice::AccessGuardDevice(int pirPin, int servoPin, ILogger* logger) : 
    pirSensor(pirPin, this), 
    servoMotor(servoPin, this),
    logger(logger) {}

void AccessGuardDevice::init() {
    Serial.begin(115200);
    servoMotor.attach();
    Serial.println("=========================================");
    Serial.println("Passive Infrared Sensor & Servo");
    Serial.println("=========================================");
}

void AccessGuardDevice::run() {
    pirSensor.checkMotion();
}


void AccessGuardDevice::on(Event event) {
    if (event == PirSensor::MOTION_DETECTED_EVENT) {
        Serial.println("Event: Motion Detected. Sending CLOSE_COMMAND to servo.");
        servoMotor.handle(ServoMotor::CLOSE_COMMAND);
    } else if (event == PirSensor::MOTION_STOPPED_EVENT) {
        Serial.println("Event: Motion Stopped. Sending OPEN_COMMAND to servo.");
        servoMotor.handle(ServoMotor::OPEN_COMMAND);
    }
}

void AccessGuardDevice::handle(Command command) {
    const char* eventLogType = nullptr;
    if (command == ServoMotor::CLOSE_COMMAND) {
        eventLogType = "MOTION_DETECTED_CLOSE";
    } else if (command == ServoMotor::OPEN_COMMAND) {
        eventLogType = "MOTION_STOPPED_OPEN";
    }

    if (eventLogType && logger) {
        logger->logEvent(eventLogType, servoMotor.getCurrentAngle());
    }
}
