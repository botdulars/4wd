#include <LiquidCrystal.h>
int pos=0; // variable to hold cursor position

LiquidCrystal lcd(2, A1, A2, A3, A4, A5);

void setup()
{
 lcd.begin(16, 2);                              //initializes 16x2 LCD
 lcd.print("Welcome To BOTDULARS Educational Kit");   //text to display
}

void loop()
{
  for(pos=0; pos<2; pos++)  
  {
    lcd.scrollDisplayLeft();    //scrolls display left by two positions
  }  
  delay(500);              //sets the speed at which display moves
}
