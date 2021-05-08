int smokeSensor = A0; 

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, A1, A2, A3, A4, A5);

void setup() {
  Serial.begin(9600); 
  lcd.begin(16,2); 
}

void loop() {
  int analogSensor = analogRead(smokeSensor); 
  Serial.print("values from the smoke sensor:"); 
  Serial.println(analogSensor); 
  lcd.setCursor(0,0); 
  lcd.print("gas, smoke:"); 
  lcd.print(analogSensor); 
  lcd.setCursor(0,1); 
  lcd.print("reading..."); 
  delay(2000); 
}
