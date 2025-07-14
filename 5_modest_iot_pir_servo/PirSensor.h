#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

#include "Sensor.h"

/**
 * @file PirSensor.h
 * @brief Declares the PirSensor class for the AccessGuard project.
 * Simplified to align with the ModestIoT framework.
 */
class PirSensor : public Sensor {
public:
  static const int MOTION_DETECTED_EVENT_ID = 10;
    static const int MOTION_STOPPED_EVENT_ID = 11;
    static const Event MOTION_DETECTED_EVENT;
    static const Event MOTION_STOPPED_EVENT;

    PirSensor(int pin, EventHandler* eventHandler = nullptr);
    void checkMotion();

private:
    int lastState;
};

#endif