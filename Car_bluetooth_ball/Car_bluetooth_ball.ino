#include<AFMotor.h>
#include<Servo.h>
#include<SoftwareSerial.h>  //for convering normal ports to serial input

// char cm;
// char s;
AF_DCMotor m1(1), m2(2), m3(3), m4(4);
SoftwareSerial myserial(A0, A1);
Servo myservo;

void setup()
{
  myserial.begin(9600);
  myservo.attach(10);
}

void front(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void left(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void right(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void frontRight(int speed)
{
  setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void frontLeft(int speed)
{
  setSpeed(speed);
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
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
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
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

void serv()
{
  myservo.write(90);
  // delay(500);
}

void servm()
{
  myservo.write(0);
}

void loop() 
{
  int sp = 125;
  if(myserial.available())
  {
    sp = 255;
    char data = myserial.read();

    switch(data)
    {
      case '1':
        sp = 255 * 0.1;
        break;

      case '2':
        sp = 255 * 0.2;
        break;

      case '3':
        sp = 255 * 0.3;
        break;

      case '4':
        sp = 255 * 0.4;
        break;

      case '5':
        sp = 255 * 0.5;
        break;

      case '6':
        sp = 255 * 0.6;
        break;

      case '7':
        sp = 255 * 0.7;
        break;

      case '8':
        sp = 255 * 0.8;
        break;

      case '9':
        sp = 255 * 0.9;
        break;

      case 'q':
        sp = 255;
        break;

      case 'F':
        front(sp);
        break;
      
      case 'B':
        back(sp);
        break;

      case 'L':
        sp =255;
        left(sp);
        break;

      case 'R':
        sp = 255;        
        right(sp);
        break;

      case 'G':
        sp = 255;
        frontLeft(sp);
        break;

      case 'I':
        sp = 255;
        frontRight(sp);
        break;

      case 'H':
        backLeft(sp);
        break;

      case 'J':
        backRight(sp);
        break;

      case 'S':
        stop();
        break;
      
      case 'D':
        stop();
        break;

      case 'W':
        serv();
        break;
      
      case 'w':
        servm();
        break;

      default:
        stop();
    }
  }
}