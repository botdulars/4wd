#include <DHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, A1, A2, A3, A4, A5);
#define DHT11_PIN 12
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHT11_PIN, DHTTYPE);
void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600); 
  dht.begin(); 
}
void loop(){
//  int chk = DHT.read11(DHT11_PIN);
  int t = dht.readTemperature(); 
  int h = dht.readHumidity(); 
  Serial.print("temp:"); Serial.print(t); Serial.print("c,humidity:"); 
  Serial.print(h); Serial.println("%"); 
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");  lcd.setCursor(0,1);
  lcd.print("Humidity: ");  lcd.print(h);
  lcd.print("%");
  delay(1000);
}
