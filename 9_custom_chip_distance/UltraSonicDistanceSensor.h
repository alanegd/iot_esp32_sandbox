#ifndef ULTRA_SONIC_DISTANCE_SENSOR_H
#define ULTRA_SONIC_DISTANCE_SENSOR_H

#include "Sensor.h"

class UltraSonicDistanceSensor : public Sensor {
public:
  static const int DISTANCE_MEASURED_EVENT_ID = 10;
  static const Event DISTANCE_MEASURED_EVENT;

  UltraSonicDistanceSensor(int echoPin, int trigPin, EventHandler* eventHandler = nullptr);

  float checkDistance();

private:
  int trigPin;
  int echoPin;
  
};

#endif