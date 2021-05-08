#include <LiquidCrystal.h>
LiquidCrystal lcd(2, A1, A2, A3, A4, A5);
const int ledPin = 4;
const int ldrPin = A7;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("LIGHT: ");
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}
void loop() {
  int ldrStatus = analogRead(ldrPin);
  lcd.setCursor(7,1);
  lcd.print(ldrStatus);
  if (ldrStatus <= 600) {  
    digitalWrite(ledPin, HIGH);
    Serial.print("Its DARK, Turn on the LED : ");
    Serial.println(ldrStatus);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.print("Its BRIGHT, Turn off the LED : ");
    Serial.println(ldrStatus);
  }
  delay(1500); 
}
