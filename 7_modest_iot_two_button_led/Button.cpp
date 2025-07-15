#include "Button.h"
#include <Arduino.h>

ButtonSensor::ButtonSensor(int pin, int eventId, EventHandler* handler) :
    Sensor(pin, handler),
    lastState(LOW),
    buttonEvent(eventId) {
    pinMode(pin, INPUT);
}


void ButtonSensor::check() {
    int currentFlickerableState = digitalRead(pin);

    if (currentFlickerableState != lastFlickerableState) {
        lastDebounceTime = millis();
    }

    lastFlickerableState = currentFlickerableState;


    if ((millis() - lastDebounceTime) <= DEBOUNCE_DELAY) {
        return;
    }

    if (currentFlickerableState == stableState) {
        return;
    }

    stableState = currentFlickerableState;

    if (stableState == HIGH) {
        Serial.print("Button on pin ");
        Serial.print(pin);
        Serial.println(" pressed (Debounced & Clean).");
        if (handler != nullptr) {
            handler->on(buttonEvent);
        }
    }
}

