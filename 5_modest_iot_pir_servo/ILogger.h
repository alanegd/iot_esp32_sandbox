#ifndef I_LOGGER_H
#define I_LOGGER_H

/**
 * @file ILogger.h
 * @brief Defines the ILogger interface for event logging.
 *
 * This abstract class provides an interface for logging systems, allowing
 * different logging strategies (e.g., remote, serial) to be used
 * interchangeably, following the Dependency Inversion Principle.
 */
class ILogger {
public:
    virtual void logEvent(const char* eventType, int servoAngle) = 0;
    virtual ~ILogger() = default;
};

#endif