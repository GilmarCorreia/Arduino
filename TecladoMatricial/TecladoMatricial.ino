
int S1 = 10,S2 =11,S3 = 12,S4=13;
int A=3,B=4,C=5,D=6,E=7,F=8,G=9;

void setup() {
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  pinMode(D,INPUT);
  pinMode(E,INPUT);
  pinMode(F,INPUT);
  pinMode(G,INPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(S4,OUTPUT);
}

void loop() {

  bool s1,s2,s3,s4;
  if(!((!digitalRead(D)) && (!digitalRead(E))&&(!digitalRead(F))&&(!digitalRead(G)))){
    s1 = (!digitalRead(A))&&digitalRead(F);
    digitalWrite(S1,s1);
  
    s2 = (digitalRead(A)&&(!digitalRead(D))) || digitalRead(E);
    digitalWrite(S2,s2);
  
    s3 = (!digitalRead(A))&&digitalRead(D) || digitalRead(C)&&(!digitalRead(F)) || digitalRead(A)&&digitalRead(F);
    digitalWrite(S3,s3);
  
    s4 = (!digitalRead(B))&&(!digitalRead(E)) || (digitalRead(B)&&digitalRead(E));
    digitalWrite(S4,s4);
 
  }
  delay(1);
}
