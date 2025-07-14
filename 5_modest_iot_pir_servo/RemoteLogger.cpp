#include "RemoteLogger.h"
#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h> 

RemoteLogger::RemoteLogger(const char* url) : endpointUrl(url) {}

void RemoteLogger::logEvent(const char* eventType, int servoAngle) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Cannot send log, WiFi not connected.");
        return;
    }

    HTTPClient http;
    http.begin(endpointUrl);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;
    doc["eventType"] = eventType;
    doc["servoAngle"] = servoAngle;
    doc["deviceId"] = "ESP32_Servo_Device_01";
    
    String jsonPayload;
    serializeJson(doc, jsonPayload);

    Serial.printf("Sending POST request to %s\n", endpointUrl);
    Serial.printf("Payload: %s\n", jsonPayload.c_str());

    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
        Serial.printf("HTTP Response code: %d\n", httpResponseCode);
        String response = http.getString();
        Serial.println(response);
    } else {
        Serial.printf("Error on sending POST: %s\n", http.errorToString(httpResponseCode).c_str());
    }

    http.end();
}