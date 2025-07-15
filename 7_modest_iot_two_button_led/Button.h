#ifndef BUTTON_SENSOR_H
#define BUTTON_SENSOR_H

#include "Sensor.h"

class ButtonSensor : public Sensor {
  public:
    /**
     * @brief Constructs a Button sensor.
     * @param pin The GPIO pin the button is connected to.
     * @param eventId The unique ID for the event this button will trigger.
     * @param handler The event handler to notify upon a press.
     */
    ButtonSensor(int pin, int eventId, EventHandler* handler = nullptr);

    void check();

  private:
    int lastState;
    Event buttonEvent;

    int lastFlickerableState; 
    int stableState;
    unsigned long lastDebounceTime;
    static const unsigned long DEBOUNCE_DELAY = 50;
};
#endif