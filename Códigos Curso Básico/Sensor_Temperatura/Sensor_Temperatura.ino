void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Temperatura: ");
  Serial.println((int)analogRead(0));
  delay(500);
}
