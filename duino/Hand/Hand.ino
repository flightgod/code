// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int time = 0;   // variable to store the number of repeat

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 9;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
 
void setup() 
{ 
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);   
} 

 
 
void loop() 
{ 
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
    wiggle();
    delay(100);
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 

  }
} 

void wiggle()
{
  for(time = 0; time < 10; time += 1)
  {
    for(pos = 0; pos < 45; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 
  delay(100);
  for(pos = 45; pos>0; pos--)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  }  
  }
}
