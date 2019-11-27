const int orangepin = LED_BUILTIN;
const int redpin = 13;
int orangeState = LOW;
int redState = LOW;
const long interval = 500;
int LED_state = 1; //orange also use 2 (red) or 3 (solid)

void delay_with_LEDs (int timedelay) {
    unsigned long startdelay = millis();
    unsigned long previousMillis = millis();
  
    //takes timedelay, led_state is a global variable
    //uses timedelay and led_state to blink/hold light for set time
    while (true) {
      unsigned long currentMillis = millis();
      if (currentMillis - startdelay >= timedelay) {
        Serial.println(timedelay, currentMillis);
        //turn only orange LED off? to make sure its in off state?
        //first part of pickup needs to be turning it on again
        //turn LED off - turn back on for next movement
        break;
      }
      //include an larger if statement that takes LED state
      //solid orange first - is that actually while moving though? -if so it shouldn't turn off...
      //when is mine detected?
      //maybe using orange only on delay...
      if (LED_state = 3) {//assuming it was turned on when first detected? - check this
        digitalWrite(orangepin, HIGH);
        continue;
      }
      if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            if (LED_state == 1) {
              if (orangeState == LOW) {
                orangeState = HIGH;
            } else {
                orangeState = LOW;
            }
              Serial.println(currentMillis, orangeState);
              digitalWrite(orangepin, orangeState); 
            }
            else if (LED_state == 2) {
              redState = !redState;
              digitalWrite(redpin, redState);
            }
      }
    }
}

void setup() {
  // put your setup code here, to run once:
  pinMode (orangepin, OUTPUT);
  pinMode (redpin, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay_with_LEDs(10000);
  LED_state = 2;
  delay_with_LEDs(10000);
  LED_state = 3;
  delay_with_LEDs(10000);
}
