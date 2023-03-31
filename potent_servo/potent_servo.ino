//for pot duita kuna ko power bich ko input
//servo R is +ve, O is control, B is for ground
//for servo, we use <servo.h> library
#define POTPIN A3 // for port connected to it
#include<Servo.h>
Servo myservo; //class define gareko
void setup() {
  pinMode(POTPIN, INPUT);
  // Serial.begin(9600);// for reading values with same baud rate as monitor
  // pinMode(LED, OUTPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(POTPIN);
  // Serial.print("Data is ");
  // Serial.println(val);
  // delay(300);
  int moto = map(val, 0, 1023, 0, 180);// map(val, inmin, inmax, outmin, outmax)
  // analogWrite(LED,ledval);
  myservo.write(moto);
}
