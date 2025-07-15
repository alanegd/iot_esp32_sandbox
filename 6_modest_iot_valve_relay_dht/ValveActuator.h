#ifndef VALVE_ACTUATOR_H
#define VALVE_ACTUATOR_H

#include "Actuator.h"

class ValveActuator : public Actuator {
public:
    // Command definitions
    static const int OPEN_VALVE_COMMAND_ID = 200;
    static const int CLOSE_VALVE_COMMAND_ID = 201;

    static const Command OPEN_VALVE_COMMAND;
    static const Command CLOSE_VALVE_COMMAND;


    ValveActuator(int pin, CommandHandler* commandHandler = nullptr);
    
    void handle(Command command) override;
    bool isOpen() const;

private:
    bool stateOpen;
};
#endif // VALVE_ACTUATOR_H