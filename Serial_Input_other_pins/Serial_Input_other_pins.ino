#include<SoftwareSerial.h>
//to convert normal pins to serial pins

SoftwareSerial myserial(9, 10);
// 9 for TX 10 for RX

void setup() {
  // put your setup code here, to run once:
  myserial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (myserial.available())
  {
    char data = myserial.read();
    Serial.println(data);
  }
}
