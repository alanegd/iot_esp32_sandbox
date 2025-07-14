#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include "Actuator.h"
#include <ESP32Servo.h>

/**
 * @file ServoMotor.h
 * @brief Declares the ServoMotor class for the AccessGuard project.
 */
class ServoMotor : public Actuator {
public:
    static const int OPEN_COMMAND_ID = 10;
    static const int CLOSE_COMMAND_ID = 11;
    static const Command OPEN_COMMAND;
    static const Command CLOSE_COMMAND;

    ServoMotor(int pin, CommandHandler* commandHandler = nullptr);
    void attach();
    void handle(Command command) override;
    int getCurrentAngle() const;

private:
    Servo servo;
    int currentAngle;
    static const int OPEN_ANGLE = 90;
    static const int CLOSED_ANGLE = 0;
};
#endif