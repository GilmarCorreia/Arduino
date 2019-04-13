#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <Adafruit_MCP4725.h>

Adafruit_ADS1115 ads(0x48);
Adafruit_MCP4725 dac;

double timer;
uint16_t i=0;

void setup(void){
  Serial.begin(230400);  
  ads.begin();
  dac.begin(0x62);
  timer = micros();
}

void loop(void) {
  int16_t adc0;

  adc0 = ads.readADC_SingleEnded(0);

  //quadrada(1,0.5);
  triangular(1);
  
  Serial.print("A0: "); 
  Serial.println((adc0*6.114)/32768);
  
}

void quadrada(float freq, float dutyCicle){
  float periodo = (1/freq)*1000000;
  
  if (micros()-timer < (periodo*dutyCicle))
    dac.setVoltage((uint16_t)4095,false);
  else if(micros()-timer < periodo)  
    dac.setVoltage((uint16_t)0,false);
  else 
    timer = micros();  
}

void triangular(float freq){
  float periodo = (1/freq)*1000000;
  
  if (micros()-timer < periodo*0.5){
    if(i<4096)
      i+=64;
    else
      i = 4095;
      
      dac.setVoltage(i,false);
  }
  else if(micros() - timer < periodo){
    if(i>0)
      i-=64;
    else
      i = 0;
      
    dac.setVoltage(i,false);
  }
  else{
    i =0;
    timer = micros();
  }
}
