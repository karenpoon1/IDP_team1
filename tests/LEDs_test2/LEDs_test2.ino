
// constants won't change. Used here to set a pin number:
const int ledPin =  8;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 500;   // interval at which to blink (milliseconds)

int ledtype = 1;
int timestart = 10000;
void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  ledtime (timestart);
  noInterrupts();
  while(1) {}
  // set the LED with the ledState of the variable:
}
