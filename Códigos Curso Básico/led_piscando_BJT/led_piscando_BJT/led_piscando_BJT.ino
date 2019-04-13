
int lendo = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(5,INPUT);
  pinMode(6,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    lendo = (Serial.read()-'0')*100;
    lendo += (Serial.read()-'0')*10;
    lendo += (Serial.read()-'0');
    analogWrite(11,lendo);
    Serial.println(lendo);
    lendo = 0;
  }
  
  if(digitalRead(5)==1){
    digitalWrite(6,HIGH);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
  }
}
