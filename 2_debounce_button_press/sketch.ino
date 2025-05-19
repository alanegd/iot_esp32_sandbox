/**
 * @file   sketch.ino
 * @brief  Demonstrates button press detection with hardware interrupt and debounce on ESP32.
 * 
 * This sketch configures a GPIO pin with a pull-up resistor as a button input,
 * attaches an interrupt to detect falling edges (button presses),
 * and implements software debounce to avoid multiple triggers due to mechanical bouncing.
 * When the button is pressed (and debounce time elapsed), it prints a message on Serial.
 * 
 * @author AlanEGD
 * @date   2025-05-18
 */

#include <Arduino.h>

#define BUTTON_PIN 12

volatile bool buttonPressed = false;
unsigned long lastInterruptTime = 0;

// Debounce delay (ms) to ignore rapid, repeated signals caused by mechanical button bounce.
const unsigned long DEBOUNCE_DELAY_MS = 200;

/**
 * @brief Interrupt Service Routine (ISR) for button press detection.
 * 
 * This ISR executes on the falling edge of the button GPIO pin.
 * It implements a simple time-based debounce by checking the elapsed time
 * since the last valid interrupt.
 */
void IRAM_ATTR buttonISR() {
  unsigned long currentTime = millis();

  if (currentTime - lastInterruptTime > DEBOUNCE_DELAY_MS) {
    buttonPressed = true;
    lastInterruptTime = currentTime;
  }
}

void setup() {
  Serial.begin(115200);

  // Configure the button pin as input with internal pull-up resistor enabled.
  // This means the pin is normally held HIGH internally, preventing floating inputs,
  // and will read LOW when the button is pressed (connecting the pin to GND).
  // Using INPUT_PULLUP eliminates the need for an external pull-up resistor,
  // ensuring stable and reliable button readings.
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Attach an interrupt to the button pin, triggering on the FALLING edge (when the button is pressed).
  // digitalPinToInterrupt converts the GPIO pin number to the interrupt number required by attachInterrupt.
  // When the button signal goes from HIGH to LOW, the ISR (buttonISR) is called immediately,
  // allowing prompt and efficient handling of the button press event without polling.
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISR, FALLING);
}

void loop() {
  if (buttonPressed) {
    Serial.println("Button pressed");
    buttonPressed = false;
  }
}
