//for pot duita kuna ko power bich ko input
//servo R is +ve, O is control, B is for ground
//for servo, we use <servo.h> library
#define LDR A1 // for port connected to it
#include<Servo.h>
Servo myservo; //class define gareko
void setup() {
  pinMode(LDR, INPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(LDR);
  // Serial.print("Data is ");
  // Serial.println(val);
  // delay(300);
  int moto = map(val, 0, 1023, 0, 180);// map(val, inmin, inmax, outmin, outmax)
  // analogWrite(LED,ledval);
  myservo.write(moto);
}
