#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);

void setup(void){
  Serial.begin(9600);  
  ads.begin();
}

void loop(void) {
  int16_t adc0,adc1,adc2,adc3, arpot;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  arpot = analogRead(1);

  
  Serial.print("AIN0: "); 
  Serial.print(adc0);
  Serial.print(" AIN1: "); 
  Serial.print(adc1);
  Serial.print(" AIN2: "); 
  Serial.print(adc2);
  Serial.print(" AIN3: "); 
  Serial.print(adc3);
  Serial.print(" pot: "); 
  Serial.println(arpot);
  
  
}
