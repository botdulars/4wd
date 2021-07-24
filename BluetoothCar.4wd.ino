//botdulars 4wd car program 
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(0,1); // for the RX and TX connectivity with bluetooth module HC05
//Motor A
const int motorPin1  = 3;  
const int motorPin2  = 5;  
//Motor B
const int motorPin3  = 6; 
const int motorPin4  = 11;  
int value = 0; 

void setup() {

  //wheels
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  BTSerial.begin(9600) ; 
  BTSerial.println("Welcome to the botdulars Car App!") ; 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BTSerial.available() )
  {
    value = BTSerial.read() ; 
    //value = Serial.parseInt(); 
    value = (int)value; 
    if (value>0 && value<5) 
    {
      Serial.println(value); 
    //value = (int)value ; 
      Serial.print("received input from app as:") ; 
      Serial.println(value) ; 
    }
    if (value==1) turnLeft(); 
    else if (value==2) goForward(); 
    else if (value==3) turnRight();
    else if (value==4) reverse(); 

    while (BTSerial.available() && BTSerial.read()); // empty buffer 
  }
}


void turnLeft()
{
    Serial.println("Turn left for half a second! Keep wheels raised so they dont run away :)");
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(700); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);  
}

void turnRight()
{
    Serial.println("Turn right for half a second! Keep them raised so they dont run away :)");
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(700); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);    
}

void reverse()
{
    Serial.println("Reverse for a  fifth of a second! Keep them raised so they dont run away :)");
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(400); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);    
}

void goForward()
{
    Serial.println("spinning wheels clockwise for half a second! Keep wheels raised so they dont run away :)");
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(700); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);  
}
