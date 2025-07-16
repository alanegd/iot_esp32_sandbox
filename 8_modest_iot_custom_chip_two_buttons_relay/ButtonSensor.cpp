#include "ButtonSensor.h"
#include <Arduino.h>

ButtonSensor::ButtonSensor(int pin, int eventId, EventHandler* handler) :
    Sensor(pin, handler),
    buttonEvent(eventId),
    lastDebounceTime(0) 
{
    pinMode(pin, INPUT_PULLUP);
    // Inicialmente, consideramos que el botón está sin presionar (HIGH).
    lastState = HIGH;
    buttonState = HIGH;
}

void ButtonSensor::check() {

    int reading = digitalRead(pin);


    if (reading != lastState) {

        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {

        if (reading != buttonState) {

            buttonState = reading;

            if (buttonState == LOW) {
                Serial.print("Button on pin ");
                Serial.print(pin);
                Serial.println(" pressed (Debounced & Clean).");

                if (handler != nullptr) {
                    handler->on(buttonEvent);
                }
            }
        }
    }

    lastState = reading;
}