// flickering LED 
int ledPin = 0; // asign LED to pin 11 
void setup() // setting things up 
{ 
pinMode(ledPin, OUTPUT); // sets pin 11 to output 
} 
void loop() // starting loop 
{ 
analogWrite(ledPin, random(50)+255); // outputs a random brightness between 206 and 255 on a scale of 255 
delay(random(100)); // maintains that brightness for a random interval between 1 and 100 milliseconds
} 
