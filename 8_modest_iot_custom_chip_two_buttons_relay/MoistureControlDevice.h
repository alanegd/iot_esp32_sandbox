#ifndef MOISTURE_CONTROL_DEVICE_H
#define MOISTURE_CONTROL_DEVICE_H

#include "Device.h"
#include "ButtonSensor.h"
#include "RelayActuator.h"

enum OperatingMode {
  MANUAL_MODE,
  AUTO_MODE
};

class MoistureControlDevice : public Device {
  public:
    MoistureControlDevice(
      int manualButtonPin, 
      int autoButtonPin, 
      int relayActuatorPin,
      int soilSensorPin
    );

    void init();
    void run();
    void on(Event event) override;
    void handle(Command command) override;

  private:
    RelayActuator relayActuator;
    ButtonSensor autoModeButton;
    ButtonSensor manualModeButton;

    int soilSensorPin; 
    OperatingMode currentMode;

    static const int AUTO_MODE_BUTTON_EVENT_ID = 301;
    static const int MANUAL_MODE_BUTTON_EVENT_ID = 302;
};
#endif