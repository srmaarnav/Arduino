/* using motor driver*/

#define I1 1
#define I2 2

void setup() {
  // put your setup code here, to run once:
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
}

void front()
{
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
}

void back()
{
  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  front();
  delay(5000);
  back();
  delay(5000);
}
