void ledtime (int delaytime) {
  while (true) {
    unsigned long currentMillis = millis();
    if (ledtype == 2) {
      digitalWrite(ledPin, HIGH);
    }
    if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    if (ledtype == 1) {
    //if the LED is off turn it on and vice-versa:
      ledState = !ledState;
    }
    digitalWrite(ledPin, ledState);
    }
    //
    if (currentMillis >= timestart) {
      return;
    }
  }
}
