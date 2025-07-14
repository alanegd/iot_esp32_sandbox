#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

/**
 * @file WiFiManager.h
 * @brief Declares the WiFiManager class for handling WiFi connectivity.
 */
class WiFiManager {
private:
    const char* ssid;
    const char* password;

public:
    WiFiManager(const char* ssid, const char* password);
    bool connect();
};

#endif