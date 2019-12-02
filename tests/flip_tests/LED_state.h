const int orangepin =  7;//change later - pins for LEDs
const int redpin = 8;
int orangeState = LOW;  // states used to set the LEDs
int redState = LOW;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 500;   // interval at which to blink (milliseconds) (0.5s for 2Hz)
 //sets initial led state to blinking orange (2 is solid orange, 3 is blinking red)

void LED_setup() {
  //sets pinmode, needs to be called in setup function of main
  pinMode (orangepin, OUTPUT);
  pinMode (redpin, OUTPUT);
}
