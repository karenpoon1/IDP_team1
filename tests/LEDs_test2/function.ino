void ledtime (int starttime) {
  unsigned long startMillis = millis();
  while (true) {
    unsigned long currentMillis = millis();
    if (currentMillis - startMillis >= starttime) {//fuck. need to record time entered loop.
      return;
    }
    if (ledtype == 2) {
      digitalWrite(redPin, LOW);
      digitalWrite(orangePin, HIGH);
    }
    if (currentMillis - previousMillis >= interval) {//hmm. hmmmmm. something orange always on?
      // save the last time you blinked the LED
      previousMillis = currentMillis;
      if (ledtype == 1) {
        orangeState = !orangeState;
        digitalWrite(orangePin, orangeState);
        digitalWrite(redPin, LOW);
      }
      else if (ledtype == 3) {
        redState = !redState;
        digitalWrite(redPin, redState);
        digitalWrite (orangePin, LOW); 
      }
    }
  }
}
