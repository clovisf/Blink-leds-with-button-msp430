/* Blink without Delay + Button

Blinks both LED's (RED and GREEN) at different
speeds depending on wether the button (S2) is
pressed or not. Runs on the MSP430G2 
LaunchPad (from Texas Instuments) 

----
Developed by Clovis Fritzen
in 10/20/2016
http://FritzenLab.com.br
For the "MSP430 LaunchPad com IDE Energia"
blog post
-----

 Based on "BlinkWithoutDelay":
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 27 Apr 2012
 by Robert Wessels
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int ledPin =  GREEN_LED;      // the number of the LED pin
const int ledPin2 =  RED_LED;
const int buttonPin = PUSH2; 

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);      
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    digitalWrite(ledPin2, !ledState);
  }
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    interval= 300;
  } else {
    interval = 100;
  }
}

