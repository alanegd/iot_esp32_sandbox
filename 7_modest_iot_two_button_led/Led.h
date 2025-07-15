#ifndef LED_ACTUATOR_H
#define LED_ACTUATOR_H

#include "Actuator.h"

class LedActuator : public Actuator {
  public:
    static const int TOGGLE_COMMAND_ID = 101;
    static const int BLINK_COMMAND_ID = 102;
    static const int TURN_OFF_COMMAND_ID = 103;

    static const Command TOGGLE_COMMAND;
    static const Command BLINK_COMMAND;
    static const Command TURN_OFF_COMMAND;

    LedActuator(int pin, CommandHandler* commandHandler = nullptr);

    void handle(Command command) override;

    /**
     * @brief Updates the LED state, required for non-blocking blinking.
     */
    void update();

private:
    void turnOff();
    void turnOn();
    void toggleState();

    bool stateOn;
    bool blinking;
    unsigned long lastBlinkTime;
    static const long BLINK_INTERVAL = 500;
};
#endif