/*
For dc motor class =
  AF_DCMotor motor(1) for 1st motor
  runs by pwm
  motor.setSpeed(255)
  motor.run();
            FORWARD
            BACKWARD
            RELEASE
*/
/*To check Motor for car*/
#include<AFMotor.h>
AF_DCMotor m1(1), m2(2), m3(3), m4(4);
void setup() {
  // put your setup code here, to run once:
  //motor.setSpeed(255);
}
void front(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}
void back(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}

void stop()
{
  // setSpeed(speed);
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}
// void turn(int speed)
// {
//   setSpeed(speed);
//   m1.run(Fo)
// }
void setSpeed(int speed)
{
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m3.setSpeed(speed);
  m4.setSpeed(speed);
}
void loop() {
  // put your main code here, to run repeatedly:
  // motor.run(FORWARD);
  // delay(1000);
  // motor.run(BACKWARD);
  // delay(1000);
  // motor.run(RELEASE);
  // delay(1000);
  front(255);
  delay(5000);
  stop();
  delay(500);
  back(255);
  delay(3000);
  stop();
  delay(500);
  front(255);
  delay(5000);
  stop();
  delay(500);
  back(190);
  delay(4000);
  stop();
  delay(500);
}
