void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,LOW);
  analogWrite(9,255);
  delay(2500);
  analogWrite(9,125);
  delay(2500);
}
