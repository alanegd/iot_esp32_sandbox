#include "DhtSensor.h"
#include "Arduino.h"

const Event DhtSensor::DATA_UPDATED_EVENT = Event(DATA_UPDATED_EVENT_ID);

DhtSensor::DhtSensor(uint8_t pin, uint8_t type, EventHandler* handler)
    : Sensor(pin, handler), dht(pin, type), temperature(0.0), humidity(0.0), lastTemperature(-100.0), lastHumidity(-100.0) {}

void DhtSensor::begin() {
    dht.begin();
}

void DhtSensor::check() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    if (t != lastTemperature || h != lastHumidity) {
        temperature = t;
        humidity = h;
        lastTemperature = t;
        lastHumidity = h;

        if (handler != nullptr) {
            handler->on(DATA_UPDATED_EVENT);
        }
    }
}