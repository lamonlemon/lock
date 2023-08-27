#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); //BlueTooth(Rx, Tx)

boolean isThereCheckSignal = false;
boolean blueConnect = false;
unsigned long previousCheckSendTime = 0;
unsigned long previousPairingCheckTime = 0;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

}

void loop() {
  if (bluetooth.available()){
    Serial.write(bluetooth.read());
  }
  if (Serial.available()){
    bluetooth.write(Serial.read());
  }

}
