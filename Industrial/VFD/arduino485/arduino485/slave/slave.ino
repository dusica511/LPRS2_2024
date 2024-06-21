//Slave node

#include<SoftwareSerial.h>

#define RS_RO    10
#define RS_DI    11
#define RS_DE_RE 12

SoftwareSerial RS_Slave(RS_RO, RS_DI);
char receivedChar;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RS_Slave.begin(9600);
  pinMode(RS_DE_RE, OUTPUT);
  //since this slave mode "Always recieve", the enable pin need to be low
  digitalWrite(RS_DE_RE, LOW);
  Serial.println("The Slave node is ready...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (RS_Slave.available()){
    Serial.write(RS_Slave.read());
  }
 
}
