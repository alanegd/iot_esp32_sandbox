/**
 * @file   main.ino
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

#define LED_PIN 14

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
