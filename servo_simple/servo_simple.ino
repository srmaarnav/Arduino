//for pot duita kuna ko power bich ko input
//servo R is +ve, O is control, B is for ground
//for servo, we use <servo.h> library
#include<Servo.h>
Servo myservo; //class define gareko
void setup() {
  myservo.attach(9);
}

void loop() {
  myservo.write(180);
  delay(300);
  myservo.write(0);
  delay(300);
}
