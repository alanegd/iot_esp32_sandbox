#include "UltraSonicDistanceSensor.h"
#include <Arduino.h>

const Event UltraSonicDistanceSensor::DISTANCE_MEASURED_EVENT = Event(DISTANCE_MEASURED_EVENT_ID);

UltraSonicDistanceSensor::UltraSonicDistanceSensor(int echoPin, int trigPin, EventHandler* eventHandler) :
  Sensor(echoPin, eventHandler),
  trigPin(trigPin),
  echoPin(echoPin)
  {
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
  }

float UltraSonicDistanceSensor::checkDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}