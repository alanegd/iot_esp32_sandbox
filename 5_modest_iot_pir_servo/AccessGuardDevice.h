#ifndef ACCESS_GUARD_DEVICE_H
#define ACCESS_GUARD_DEVICE_H

#include "Device.h"
#include "PirSensor.h"
#include "ServoMotor.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include "ILogger.h"

/**
 * @file AccessGuardDevice.h
 * @brief Declares the main device class for the AccessGuard project.
 * Adds logic to handle the PIR sensor's stabilization period.
 */
class AccessGuardDevice : public Device {
private:
    PirSensor pirSensor;
    ServoMotor servoMotor;
    ILogger* logger;

public:
    AccessGuardDevice(int pirPin, int servoPin, ILogger* logger);
    void init();
    void run();
    
     /**
     * @brief Handles events from components (e.g., sensor updates).
     * @param event The event that occurred.
     */
    void on(Event event) override;

    /**
     * @brief Handles commands (required by the Device interface).
     * @param command The command to handle.
     */    
    void handle(Command command) override;
};

#endif