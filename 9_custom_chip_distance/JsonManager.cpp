#include "JsonManager.h"
#include <Arduino.h>

JsonManager::JsonManager() {}

void JsonManager::printJson(String operationMode, float currentFuelFlow, float fuelLevelDistance) {
  StaticJsonDocument<200> doc;

  doc["deviceMacAddress"] = getMacAddress();
  doc["operationMode"] = operationMode;
  doc["currentFuelFlow"] = currentFuelFlow;
  doc["fuelLevelDistance"] = fuelLevelDistance;
  doc["createdAt"] = "2025-07-16T00:20:00Z"; 

  serializeJson(doc, Serial);
  Serial.println();
}

String JsonManager::getMacAddress() {
  return WiFi.macAddress();
}