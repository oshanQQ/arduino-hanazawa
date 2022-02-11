
#include "Arduino.h"
#include "SPI.h"
#include "AE_MPL115A1.h"
#include <Servo.h>

Servo handler;

void setup() {
  Serial.begin(9600);
  Serial.println("MPL115A1 Test.");
  //MPL115A1　初期化 
  SPI_MPL115A1_Init();
  //MPL115A1　補正データ読出し
  SPI_MPL115A1_ReadCoefficient();  
  //Arduinoに接続するピンを決める
  handler.attach(6);

}

void loop() {
  //MPL115A1　気圧のＡＤ値読出し
  SPI_MPL115A1_ReadPressure();
  
  float pressure = SPI_MPL115A1_Pressure();
  float temp = SPI_MPL115A1_Temp();
  float height = SPI_MPL1151A1_Height(pressure, temp);

  Serial.print(pressure);
  Serial.print("hPa\n");
  Serial.print(temp);
  Serial.print("deg\n");
  Serial.print(height);
  Serial.print("m");
  Serial.print("\n");
  Serial.print("----------------------------------");
  Serial.print("\n");
  delay(60000);

//  if (height > 10) {
//    handler.write(0);
//  } else {
//    handler.write(90);
//  }
  
  handler.write(0);
  
  delay(600000);

  handler.write(90);
}

float SPI_MPL1151A1_Height(float pressure, float temp) {
  float h;
  h = (pow((1013 / (pressure * 10)), 1 / 5.3) - 1) * (15 + 273) / 0.0065;
  return h;
}
