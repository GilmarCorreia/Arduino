boolean controle = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  double valor = (double)((analogRead(0)/(double)(1024))*5);
  if(valor>=4.3){
    digitalWrite(8,LOW);
    controle = 0;
  }
  else if(controle == 1){ 
    digitalWrite(8,HIGH);
  }
  else if(valor<0.5){
    controle = 1;
  }
  Serial.print("Voltagem: ");
  Serial.println(valor);
  delay(500);
}
