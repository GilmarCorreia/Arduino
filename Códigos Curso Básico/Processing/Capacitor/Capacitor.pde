import cc.arduino.*;
import org.firmata.*;
import processing.serial.*;


Arduino uno = new Arduino(this,Arduino.list()[1],57600);
public static boolean controle = true;
public static int x = 0,y=700;
public static int x2 = 0,y2=700;
void setup(){
  background(0);
  size(1500,700);
}

void draw(){
  
  stroke(255);
  fill(255);
  ellipse(x,y,5,5);
  
  float valor = uno.analogRead(0); 
  y=700-(int)map(valor,0,1024,0,700);

  stroke(255,0,0);
  fill(255,0,0);
  ellipse(x,y2,5,5);
  
  float valor2=uno.analogRead(5);
  y2=700-(int)map(valor2,0,1024,0,700);

  x++;
  
  if(x>=1500){
    background(0);
    x = 0;  
  } 
}
