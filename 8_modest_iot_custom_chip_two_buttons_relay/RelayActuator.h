#ifndef RELAY_ACTUATOR_H
#define RELAY_ACTUATOR_H

#include "Actuator.h"

class RelayActuator : public Actuator {
  public:
    static const int TURN_ON_COMMAND_ID = 200;
    static const int TURN_OFF_COMMAND_ID = 201;
    static const int TOGGLE_COMMAND_ID = 202;

    static const Command TURN_ON_COMMAND;
    static const Command TURN_OFF_COMMAND;
    static const Command TOGGLE_COMMAND;

    RelayActuator(int pin, CommandHandler* commandHandler = nullptr);

    void handle(Command command) override;
    bool isOn() const;

  private:
    bool stateOn;
};

#endif