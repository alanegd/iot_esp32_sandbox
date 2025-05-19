/**
 * @file   sketch.ino
 * @brief  Demonstrates button press detection with debounce and LED control on ESP32.
 * 
 * This sketch uses an interrupt to detect button presses and toggles an LED state.
 * It includes a debounce mechanism to prevent false triggers from button bouncing.
 * The LED is turned on when the button is pressed and turned off when pressed again.
 * The button is connected to GPIO 12 and the LED to GPIO 14.
 * The button is configured with an internal pull-up resistor.
 * 
 * @author AlanEGD
 * @date   2025-05-18
 */

#define LED_PIN 14
#define BUTTON_PIN 12

volatile bool buttonPressed = false;
unsigned long lastInterruptTime = 0;
const unsigned long DEBOUNCE_DELAY_MS = 200;

bool ledState = false;

void IRAM_ATTR buttonISR() {
  unsigned long currentTime = millis();

  if (currentTime - lastInterruptTime > DEBOUNCE_DELAY_MS) {
    buttonPressed = true;
    lastInterruptTime = currentTime;
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISR, FALLING);
}

void loop() {
  if (buttonPressed) {
    buttonPressed = false;

    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
  }
}
