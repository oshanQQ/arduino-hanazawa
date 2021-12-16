void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(1, HIGH);
  delay(500);
  digitalWrite(1, LOW);
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
}
