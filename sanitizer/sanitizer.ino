int motor1pin1 = 5;
int motor1pin2 = 3;

int trig = A1;
int echo = A0;
float time_taken, distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,HIGH);
  delay(100);
  digitalWrite(trig,LOW);
  time_taken = pulseIn(echo, HIGH);
  distance = 0.017 * time_taken;
  Serial.println(distance);
  if (distance < 10)
  {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    delay(2500);
    // digitalWrite(motor1pin1, LOW);
    // digitalWrite(motor1pin2, LOW);
  }
  else
  {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    // delay(5000);
  }
}
