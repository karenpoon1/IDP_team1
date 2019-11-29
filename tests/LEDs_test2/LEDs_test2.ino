
// constants won't change. Used here to set a pin number:
const int orangepin =  7;// the number of the LED pin
const int redpin = 6;

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
  pinMode(orangepin, OUTPUT);
  pinMode(redpin, OUTPUT);
}

void loop() {
  ledtype = 3;
  ledtime (delaytime);
  ledtype = 1;
  ledtime (delaytime);
  ledtype = 2;
  ledtime (delaytime);
  unsigned long blinktime;
  ledtype = 1;
  for (int i = 0; i <= 500; i++){
    if (i = 0){
      unsigned long millisnow = millis();
      blinktime = LED_call(millisnow);
    }
    else {
      blinktime = LED_call(blinktime);
    }
    delay(10);
  }
  delay(2000);
  ledtype = 2;
  ledtime (delaytime);
  // set the LED with the orangeState of the variable:
}
