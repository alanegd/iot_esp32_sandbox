#ifndef BUTTON_SENSOR_H
#define BUTTON_SENSOR_H

#include "Sensor.h"

class ButtonSensor : public Sensor {
  public:
    ButtonSensor(int pin, int eventId, EventHandler* handler = nullptr);
    void check();

  private:
    Event buttonEvent;

    int lastState;
    int buttonState;
    unsigned long lastDebounceTime;
    static const unsigned long DEBOUNCE_DELAY = 50;

};
#endif