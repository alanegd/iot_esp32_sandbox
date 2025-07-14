#include <WiFi.h>
#include "WiFiManager.h"
#include "RemoteLogger.h"
#include "AccessGuardDevice.h"

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";
const char* SERVER_ENDPOINT = "https://endpoint";

const int PIR_PIN = 2;
const int SERVO_PIN = 27;

WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD);
RemoteLogger remoteLogger(SERVER_ENDPOINT);
AccessGuardDevice device(PIR_PIN, SERVO_PIN, &remoteLogger);

void setup() {
  wifiManager.connect();
  device.init();
}

void loop() {
  device.run();
}