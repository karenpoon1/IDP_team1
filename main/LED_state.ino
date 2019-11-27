const int orangePin =  LED_BUILTIN;//change later - pins for LEDs
const int redPin = 10;
int orangeState = LOW;  // states used to set the LEDs
int redState = LOW;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 500;   // interval at which to blink (milliseconds) (0.5s for 2Hz)

void led_setup() {
  //sets pinmode, needs to be called in setup function of main
  pinMode (orangepin, OUTPUT);
  pinMode (redpin, OUTPUT);
}

void delay_with_LEDs (int starttime) {
  //record function start time
  unsigned long startMillis = millis();
  while (true) { //loop continues until delay needed is over
    unsigned long currentMillis = millis();
    if (currentMillis - startMillis >= starttime) {
      return;//exit loop when delay reached
    }
    if (ledtype == 2) {//solid orange light (mine detected)
      digitalWrite(redPin, LOW);
      digitalWrite(orangePin, HIGH);
    }
    if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;
      if (ledtype == 1) {//flashing orange light (normal movement)
        orangeState = !orangeState;
        digitalWrite(orangePin, orangeState);
        digitalWrite(redPin, LOW);
      }
      else if (ledtype == 3) {//flashing red light (transporting mine)
        redState = !redState;
        digitalWrite(redPin, redState);
        digitalWrite (orangePin, LOW); 
      }
    }
  }
}
