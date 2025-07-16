#include "FirstStudentDevice.h"
#include <Arduino.h>

FirstStudentDevice::FirstStudentDevice(int echoPin, int trigPin, int flowPin) :
  ultraSonicDistanceSensor(echoPin, trigPin, this),
  flowSensorPin(flowPin)
{}

void FirstStudentDevice::init() {
  pinMode(flowSensorPin, INPUT);
}

void FirstStudentDevice::run() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float distance = ultraSonicDistanceSensor.checkDistance();
    float rawFlowValue = analogRead(flowSensorPin);
    float flowValue = map(rawFlowValue, 0, 4095, 0, 187.5);
    String operationMode = (flowValue > 0.1) ? "ACTIVE" : "STAND_BY";

    jsonManager.printJson(operationMode, flowValue, distance);
  }
}

void FirstStudentDevice::on(Event event) {

}

void FirstStudentDevice::handle(Command command) {

}