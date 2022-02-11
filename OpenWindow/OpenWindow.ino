#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Servo.h>
 
TinyGPSPlus gps;
Servo handler;
SoftwareSerial mySerial(10, 11); // RX, TX
//TinyGPSCustom magneticVariation(gps, "GPRMC", 10);

int OPEN = 0;
int CLOSE = 90;
 
void setup() {
 // Open serial communications and wait for port to open:
 Serial.begin(9600);
 handler.attach(6);
 while (!Serial) {
 ; // wait for serial port to connect. Needed for native USB port only
 }
 
 Serial.println("Goodnight moon!");
 
 // set the data rate for the SoftwareSerial port
 mySerial.begin(9600);
 mySerial.println("Hello, world?");
}
 
void loop() { // run over and over
  char c = mySerial.read();
  //Serial.print(c);
  gps.encode(c);
  if (gps.location.isUpdated()){
    Serial.print("LAT="); Serial.println(gps.location.lat(), 6);
    Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
    Serial.print("ALT="); Serial.println(gps.altitude.meters());
    Serial.print("-----------\n");

    if (gps.altitude.meters() > 20) {
      handler.write(OPEN);
      Serial.print("Open!!!!!\n");
    } else {
      handler.write(CLOSE);
      Serial.print("Close!!!!\n");
    }
    delay(1000);
  }
  
}
