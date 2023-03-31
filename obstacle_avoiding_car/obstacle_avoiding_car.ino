#include<AFMotor.h>

char cm;
char s;
AF_DCMotor m1(1), m2(2), m3(3), m4(4);
int trig = A0;
int echo = A1;
float time_taken, distance;
int ran;
int dl = 1000;
int dl1 = 1300;
int mind = 60;

void setup()
{
  // put your setup code here, to run once:
  //motor.setSpeed(255);
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  s = 100;
}
void front(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}
void left(int speed)
{
  setSpeed(speed);
  m2.run(FORWARD);
  m1.run(FORWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}
void right(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}
void frontRight(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}
void frontLeft(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}
void backRight(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}

void backLeft(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
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

void setSpeed(int speed)
{
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m3.setSpeed(speed);
  m4.setSpeed(speed);
}

void loop() 
{
  digitalWrite(trig,HIGH);
  delay(50);
  digitalWrite(trig,LOW);
  time_taken = pulseIn(echo, HIGH);
  distance = 0.017 * time_taken;
  Serial.println(distance);
  if(distance < mind)
  {
    ran = random(1,7);
  }
  ran = random(1,4);
  Serial.println(ran);
  if(distance > mind)
  {
    front(s);
  }
  else if(ran == 1 && distance < mind)
  { 
    stop();
    delay(dl);
    back(140);
    delay(dl1);
  }
  else if(ran == 2 && distance < mind)
  {
    stop();
    back(140);
    delay(dl);
    left(255);
    delay(dl1);
  }
  else if(ran == 3 && distance < mind)
  {
    stop();
    back(140);
    delay(dl);
    right(255);
    delay(dl1);
  }
  else if(ran == 4 && distance < mind)
  {
    stop();
    back(140);
    delay(dl);
    frontRight(s);
  }
  else if(ran == 5 && distance < mind)
  {
    stop();
    back(140);
    delay(dl);
    frontLeft(s);
  }
  else if(ran == 6 && distance < mind)
  {
    stop();
    back(140);
    delay(dl);
    backLeft(s);
    delay(dl1);
  }
  else if(ran == 7 && distance < mind)
  {
    stop();
    back(140);
    delay(dl);
    backRight(s);
    delay(dl1);
  }
}



