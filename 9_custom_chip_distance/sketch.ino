#import "FirstStudentDevice.h"

const int ECHO_PIN = 22;
const int TRIG_PIN = 23;
const int FLOW_PIN = 6;

FirstStudentDevice device(ECHO_PIN, TRIG_PIN, FLOW_PIN);

void setup() {
  Serial.begin(115200);
  device.init();
}

void loop() {
  device.run();
  delay(10);
}
