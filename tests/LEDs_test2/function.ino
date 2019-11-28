void ledtime (int starttime) {
  unsigned long startMillis = millis();
  while (true) {
    unsigned long currentMillis = millis();
    if (currentMillis - startMillis >= starttime) {//fuck. need to record time entered loop.
      return;
    }
    if (ledtype == 2) {
      digitalWrite(redpin, LOW);
      digitalWrite(orangepin, HIGH);
    }
    if (currentMillis - previousMillis >= interval) {//hmm. hmmmmm. something orange always on?
      // save the last time you blinked the LED
      previousMillis = currentMillis;
      if (ledtype == 1) {
        orangeState = !orangeState;
        digitalWrite(orangepin, orangeState);
        digitalWrite(redpin, LOW);
      }
      else if (ledtype == 3) {
        redState = !redState;
        digitalWrite(redpin, redState);
        digitalWrite (orangepin, LOW); 
      }
    }
  }
}

unsigned long LED_call (unsigned long previousMillis) {//takes time of previous blink - first call in function seperately defined?
  unsigned long currentMillis = millis();//measures current time
  if (ledtype == 2) {//solid orange light (mine detected)
      digitalWrite(redpin, LOW);
      digitalWrite(orangepin, HIGH);
    }
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;//update this if blink happens, essentially
    if (ledtype == 1) {//flashing orange light (normal movement)
      orangeState = !orangeState;
      digitalWrite(orangepin, orangeState);
      digitalWrite(redpin, LOW);
    }
    else if (ledtype == 3) {//flashing red light (transporting mine)
      redState = !redState;
      digitalWrite(redpin, redState);
      digitalWrite (orangepin, LOW); 
    }
    return previousMillis;//changed if blink happened, otherwise same as input value
  }
}
