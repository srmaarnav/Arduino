//for pot duita kuna ko power bich ko input
#define POTPIN A3 // for port connected to it
#define LED 3
void setup() {
  // put your setup code here, to run once:
  pinMode(POTPIN, INPUT);
  Serial.begin(9600);// for reading values with same baud rate as monitor
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(POTPIN);
  Serial.print("Data is ");
  Serial.println(val);
  delay(300);
  int ledval = map(val, 0, 1023, 0, 255);// map(val, inmin, inmax, outmin, outmax)
  analogWrite(LED,ledval);
}
