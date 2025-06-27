#ifndef AMBIENT_DISPLAY_DEVICE_H
#define AMBIENT_DISPLAY_DEVICE_H

#include "Device.h"
#include "DhtSensor.h"
#include "LcdDisplay.h"

class AmbientDisplayDevice : public Device {
public:
    AmbientDisplayDevice(uint8_t dhtPin, uint8_t lcdAddress);
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

private:
    DhtSensor dhtSensor;
    LcdDisplay lcdDisplay;

    void updateDisplay();
};

#endif // AMBIENT_DISPLAY_DEVICE_H