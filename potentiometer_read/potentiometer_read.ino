#define POTPIN A3 // for port connected to it
void setup() {
  // put your setup code here, to run once:
  pinMode(POTPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(POTPIN);
  Serial.print("Data is ");
  Serial.println(val);
  delay(300);
}
