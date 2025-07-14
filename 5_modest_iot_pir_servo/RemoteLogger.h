#ifndef REMOTE_LOGGER_H
#define REMOTE_LOGGER_H

#include "ILogger.h"

/**
 * @file RemoteLogger.h
 * @brief Declares the RemoteLogger class.
 *
 * This class implements the ILogger interface to send log data in JSON
 * format to a remote REST endpoint via HTTP POST.
 */
class RemoteLogger : public ILogger {
private:
    const char* endpointUrl;

public:
    RemoteLogger(const char* url);
    void logEvent(const char* eventType, int servoAngle) override;
};

#endif