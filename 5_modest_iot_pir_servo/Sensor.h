#ifndef SENSOR_H
#define SENSOR_H

#include "EventHandler.h"

/**
 * @file Sensor.h
 * @brief Declares the Sensor base class.
 * This class now includes a getPin() method.
 */
class Sensor : public EventHandler {
protected:
    int pin;
    EventHandler* handler;

public:
    Sensor(int pin, EventHandler* eventHandler = nullptr);
    void on(Event event) override;
    void setHandler(EventHandler* eventHandler);
};

#endif