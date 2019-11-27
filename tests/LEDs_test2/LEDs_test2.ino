
// constants won't change. Used here to set a pin number:
const int orangePin =  LED_BUILTIN;// the number of the LED pin
const int redPin = 10;

// Variables will change:
int orangeState = LOW;  // orangeState used to set the LED
int redState = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 500;   // interval at which to blink (milliseconds)

int ledtype = 1;
int delaytime = 5000;
void setup() {
  // set the digital pin as output:
  pinMode(orangePin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  ledtype = 3;
  ledtime (delaytime);
  ledtype = 1;
  ledtime (delaytime);
  ledtype = 2;
  ledtime (delaytime);
  //delay(2000);
  //ledtype = 1;
  //ledtime (timestart);
  // set the LED with the orangeState of the variable:
}
