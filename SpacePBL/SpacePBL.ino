#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  int value = EEPROM.length();
  Serial.println(value);  
}

void loop() {
  
}
