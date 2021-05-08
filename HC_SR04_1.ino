
#include<LiquidCrystal.h>

LiquidCrystal lcd(2, A1, A2, A3, A4,A5); //Interface pins of the LCD 
const int trig_pin=8;
const int echo_pin=9;
long distance,duration;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0); //set the cursor to column 0 and line 0
  lcd.write("Distance: ");
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
}


void loop() {
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(20);
  duration = pulseIn(echo_pin, HIGH); //To receive the reflected signal.
  distance= duration*0.034/2;
  lcd.setCursor(0,1); //set the cursor to column 0 and line 1
  lcd.print(distance);
  lcd.print(" cm ");
  delay(500);
}
