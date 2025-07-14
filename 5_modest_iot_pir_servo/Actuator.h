#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "CommandHandler.h"

/**
 * @file Actuator.h
 * @brief Declares the Actuator base class.
 */
class Actuator : public CommandHandler {
protected:
    int pin;
    CommandHandler* handler;

public:
    Actuator(int pin, CommandHandler* commandHandler = nullptr);
    virtual void handle(Command command);
    void setHandler(CommandHandler* commandHandler);
};

#endif