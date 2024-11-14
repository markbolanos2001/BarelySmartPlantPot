/* 
Barely Smart Plant Pot v1

by Mark Bolanos
*/

#include <RGBLed.h>     //https://github.com/wilmouths/RGBLed/tree/master -- link to the lib


#define analogInpPin 26 // Analogue inp pin for the soil sensor
#define ledRed 2
#define ledBlue 3
#define ledGreen 4

RGBLed led(ledRed, ledGreen, ledBlue, RGBLed::COMMON_CATHODE);  // Instantiate the LED object





void isDry(){
  led.setColor(RGBLed::RED);
}

void isMoist(){
  led.setColor(RGBLed::BLUE);
}

void isHalfMoist(){
  led.setColor(RGBLed::YELLOW);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(analogInpPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  
  // Start off with led off and then fade in to purple
  led.off();
  led.fadeIn(RGBLed::MAGENTA,500, 5000);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  int moistVal = analogRead(analogInpPin);
  Serial.println(moistVal);
  
  // Far from final , just an idea to test things out
  if (moistVal > 220){
    isMoist();
  } else if (moistVal < 220 && moistVal > 90){
    isHalfMoist();
  } else if (moistVal < 90){
    isDry();
  }
  delay(5000);
  
}
