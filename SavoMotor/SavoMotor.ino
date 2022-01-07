#include <Servo.h>
Servo handler;

void setup() {
  handler.attach(6);
}

void loop() {
  handler.write(0);
  delay(500);
  handler.write(90);
  delay(500);
}
