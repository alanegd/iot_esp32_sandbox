#include "Button.h"
#include <Arduino.h>

ButtonSensor::ButtonSensor(int pin, int eventId, EventHandler* handler) :
    Sensor(pin, handler),
    lastState(LOW),
    buttonEvent(eventId) {
    pinMode(pin, INPUT);
}


void ButtonSensor::check() {
    int currentState = digitalRead(pin);

    if (currentState != lastState) {
        delay(50);
        currentState = digitalRead(pin);
        if (currentState == HIGH && lastState == LOW) {
            Serial.print("Button on pin ");
            Serial.print(pin);
            Serial.println(" pressed.");
            if (handler != nullptr) {
                handler->on(buttonEvent);
            }
        }
    }
    lastState = currentState;
}

