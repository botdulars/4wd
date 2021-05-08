#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, A1, A2, A3, A4, A5);
int potPin1 = A6;
void setup()
{
// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(potPin1, INPUT);
}

void loop()
{
  int sensorValue = analogRead(potPin1);  
  lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
  lcd.print("SensorValue:"); // Prints Sensor Val: to LCD
  if (sensorValue<1000) lcd.print(" ");
  lcd.print(sensorValue); // Prints value on Potpin1 to LCD
  delay(1000);
}
                           
