const int buzzer = 7; //buzzer to arduino pin 4


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 4 as an output
 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(2000);        // ...for 2 sec
  noTone(buzzer);     // Stop sound...

}

void loop(){
  
}
