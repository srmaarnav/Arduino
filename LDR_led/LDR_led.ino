//LDR ko lagi euta power arko ground
//glows in dark
#define LDR A1 // for port connected to it
#define LED 3
void setup() {
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(LDR);
  Serial.println(val);
  delay(500);
  if(val==0)
    digitalWrite(LED, LOW);
  else
    digitalWrite(LED, HIGH);
}
