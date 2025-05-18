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
