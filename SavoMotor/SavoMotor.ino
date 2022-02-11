#include <Servo.h>
Servo handler;

int OPEN = 0;
int CLOSE = 90;

void setup() {
  handler.attach(6);
}

void loop() {
  // 電源を入れた後の1分間は、扉を開かない
  delay(60000);

  // 扉を5分開く
  handler.write(OPEN);
  Serial.print("Open!!\n");
  delay(300000);

  // 扉を閉める
  handler.write(CLOSE);
  Serial.print("Close...\n");
  delay(1000);
};
