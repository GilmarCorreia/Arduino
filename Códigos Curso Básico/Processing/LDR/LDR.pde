import cc.arduino.*;
import org.firmata.*;
import processing.serial.*;


Arduino uno = new Arduino(this,Arduino.list()[1],57600);

void setup(){
  size(1024,1024);
}

void draw(){
  
  background(255-(uno.analogRead(0)/4),150,150);
}
