#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); //BlueTooth(Rx, Tx)

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  bluetooth.begin(38400);

}

void loop() {
  if (bluetooth.available()){
    Serial.write(bluetooth.read());
  } 
  if (Serial.available()){
    bluetooth.write(Serial.read());
  }

}
