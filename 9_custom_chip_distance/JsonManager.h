#ifndef JSON_MANAGER_H
#define JSON_MANAGER_H

#include <ArduinoJson.h>
#include <WiFi.h>

class JsonManager {
public:
  JsonManager();
  void printJson(String operationMode, float currentFuelFlow, float fuelLevelDistance);

private:
  String getMacAddress();
};

#endif