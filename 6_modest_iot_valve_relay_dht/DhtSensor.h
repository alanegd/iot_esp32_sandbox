#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <DHT.h>
#include "Sensor.h"

class DhtSensor : public Sensor {
public:
    static const int DATA_UPDATED_EVENT_ID = 100;
    static const Event DATA_UPDATED_EVENT;

    float temperature;
    float humidity;

    /**
     * @brief Constructs a DhtSensor.
     * @param pin The GPIO pin connected to the DHT sensor's data line.
     * @param type The type of DHT sensor (e.g., DHT22).
     * @param handler The EventHandler to notify of new data.
     */
    DhtSensor(uint8_t pin, uint8_t type, EventHandler* handler = nullptr);

    /**
     * @brief Initializes the DHT sensor.
     */
    void begin();

    /**
     * @brief Reads the sensor and fires an event if new data is available.
     */
    void check();

private:
    DHT dht;
    float lastTemperature;
    float lastHumidity;
};

#endif // DHT_SENSOR_H