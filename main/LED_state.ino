LED_setup() {
  const int ledPin = LED_BUILTIN; //change for actual LED pin
  //add red ledpin - change names
  int orangeState = LOW;
  int redState = LOW;
  const long interval = 500;
  pinMode (ledPin, OUTPUT);
  //pinMode (ledPinred, OUTPUT);
}

void delay_with_LEDs (int timedelay) {
    unsigned long startdelay = millis();
    unsigned long previousMillis = millis();
  
    //takes timedelay, led_state is a global variable
    //uses timedelay and led_state to blink/hold light for set time
    while (true) {
      unsigned long currentMillis = millis();
      if (currentMillis - startdelay >= timedelay) {
        //turn only orange LED off? to make sure its in off state?
        //first part of pickup needs to be turning it on again
        //turn LED off - turn back on for next movement
        break
      }
      //include an larger if statement that takes LED state
      //solid orange first - is that actually while moving though? 
      //maybe using orange only on delay...
      else if (currentMillis - previousMillis >= 500) {
            previousMillis = currentMillis;
            //change LED state - which colour though?
            //    if (ledState == LOW) {
      //ledState = HIGH;
    //} else {
    //  ledState = LOW;
    //}
    //    digitalWrite(ledPin, ledState);
      }
    }
}
