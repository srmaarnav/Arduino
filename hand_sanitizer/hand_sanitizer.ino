int trig = 9;
int echo = 8;
int motor = 4;
float time_taken, distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(motor,HIGH);
  digitalWrite(trig,HIGH);
  delay(500);
  digitalWrite(trig,LOW);
  time_taken = pulseIn(echo, HIGH);
  distance = 0.017 * time_taken;
  Serial.println(distance);
  // if (distance < 10)
  // {
  //   digitalWrite(motor,HIGH);
  //   delay(500);
  //   // digitalWrite(motor,LOW);
  // }
  // // else
  // // {
  // //   digitalWrite(motor,LOW);
  // // }
}