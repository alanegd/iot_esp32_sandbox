#ifndef ALTER_MODE_DEVICE_H
#define ALTER_MODE_DEVICE_H

#include "Device.h"
#include "Led.h"
#include "Button.h"

class AlterModeDevice : public Device {
  public:
    AlterModeDevice(int ledPin, int blinkButtonPin, int toggleButtonPin);

    void init();

    void run();

    void on(Event event) override;

    void handle(Command command) override;

  private:
    LedActuator ledActuator;
    ButtonSensor blinkModeButton;
    ButtonSensor toggleOnOffButton;

    static const int BLINK_MODE_BUTTON_EVENT_ID = 201;
    static const int TOGGLE_ON_OFF_BUTTON_EVENT_ID = 202;

};
#endif