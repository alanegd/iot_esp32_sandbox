#include "PirSensor.h"
#include <Arduino.h>

/**
 * @file PirSensor.cpp
 * @brief Implements the simplified PirSensor class.
 */
const Event PirSensor::MOTION_DETECTED_EVENT = Event(MOTION_DETECTED_EVENT_ID);
const Event PirSensor::MOTION_STOPPED_EVENT = Event(MOTION_STOPPED_EVENT_ID);

PirSensor::PirSensor(int pin, EventHandler* eventHandler)
    : Sensor(pin, eventHandler), lastState(LOW) {
    pinMode(pin, INPUT);
}

void PirSensor::checkMotion() {
    int currentState = digitalRead(pin);
    if (currentState != lastState) {
        if (currentState == HIGH) {
            on(MOTION_DETECTED_EVENT);
        } else {
            on(MOTION_STOPPED_EVENT);
        }
        lastState = currentState;
    }
}