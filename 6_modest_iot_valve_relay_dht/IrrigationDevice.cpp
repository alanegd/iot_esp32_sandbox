/**
 * @file IrrigationDevice.cpp
 * @brief Implements the IrrigationDevice class.
 * @author Alan Enrique Galavis Du Bois (202110223)
 * @date June 27, 2025
 */
#include "IrrigationDevice.h"
#include <Arduino.h>

IrrigationDevice::IrrigationDevice(uint8_t dhtPin, uint8_t valvePin) : 
    dhtSensor(dhtPin, DHT22, this),
    valveActuator(valvePin, this) {}

void IrrigationDevice::init() {
    dhtSensor.begin();
}

void IrrigationDevice::run() {
    dhtSensor.check();
}

void IrrigationDevice::on(Event event) {
    if (event == DhtSensor::DATA_UPDATED_EVENT) {
        Serial.printf("Sensor Update -> Temp: %.1f C, Hum: %.1f %%\n", dhtSensor.temperature, dhtSensor.humidity);
        checkIrrigationNeeds();
    }
}

void IrrigationDevice::handle(Command command) {

}

void IrrigationDevice::checkIrrigationNeeds() {
    float temp = dhtSensor.temperature;
    float hum = dhtSensor.humidity;
    
    bool wasOpen = valveActuator.isOpen();

    if (temp > 30.0 || hum < 40.0) {
        valveActuator.handle(ValveActuator::OPEN_VALVE_COMMAND);
    } else {
        valveActuator.handle(ValveActuator::CLOSE_VALVE_COMMAND);
    }

    bool isOpenNow = valveActuator.isOpen();
    
    if (wasOpen != isOpenNow) {
        Serial.printf("Device Update -> Irrigation valve is now %s.\n", isOpenNow ? "OPEN" : "CLOSED");
    }
}