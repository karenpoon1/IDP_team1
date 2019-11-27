const int orangepin = 12;
const int redpin = 13;
int orangeState = LOW;
int redState = LOW;
const long interval = 500;
char LED_state = o; //orange also use r (red) or s(solid) CHANEG

void led_setup() {
  pinMode (orangepin, OUTPUT);
  pinMode (redpin, OUTPUT);
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
      //solid orange first - is that actually while moving though? -if so it shouldn't turn off...
      //when is mine detected?
      //maybe using orange only on delay...
      if (LED_state = s) {//assuming it was turned on when first detected? - check this
        continue;
      }
      if (currentMillis - previousMillis >= 500) {
            previousMillis = currentMillis;
            if (LED_state == o) {
              orangeState = !orangeState;
              digitalWrite(orangepin, orangeState); 
            }
            else if (LED_state == r) {
              redState = !redState;
              digitalWrite(redpin, redState);
            }
