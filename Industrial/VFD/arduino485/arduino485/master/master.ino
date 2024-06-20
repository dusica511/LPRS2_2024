//Master node

#include <SoftwareSerial.h>

#define RS_RO    10
#define RS_DI    11
#define RS_DE_RE 12

SoftwareSerial RS_Master(RS_RO, RS_DI); //RX,TX

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
RS_Master.begin(9600);
pinMode(RS_DE_RE, OUTPUT);
//master need to activate RS_DE_RE to high to start transmition
digitalWrite(RS_DE_RE, HIGH);
Serial.println("Master node is ready...");
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available())
RS_Master.write(Serial.read());
}
