#ifndef FIRST_STUDENT_DEVICE_H
#define FIRST_STUDENT_DEVICE_H

#include "Device.h"
#include "UltraSonicDistanceSensor.h"
#include "JsonManager.h"

class FirstStudentDevice : public Device {
  public:
    FirstStudentDevice(int echoPin, int trigPin, int flowPin);

    void init();
    void run();
    void on(Event event) override;
    void handle(Command command) override;

  private:
    UltraSonicDistanceSensor ultraSonicDistanceSensor;
    JsonManager jsonManager;
    int flowSensorPin;
    unsigned long previousMillis = 0;
    const long interval = 5000;
};

#endif