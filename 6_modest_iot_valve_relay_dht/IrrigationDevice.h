#ifndef IRRIGATION_DEVICE_H
#define IRRIGATION_DEVICE_H

#include "Device.h"
#include "DhtSensor.h"
#include "ValveActuator.h"

class IrrigationDevice : public Device {
public:
    IrrigationDevice(uint8_t dhtPin, uint8_t valvePin);

    void init();
    void run();
    void on(Event event) override;
    void handle(Command command) override;

private:
    DhtSensor dhtSensor;
    ValveActuator valveActuator;

    void checkIrrigationNeeds();
};
#endif // IRRIGATION_DEVICE_H