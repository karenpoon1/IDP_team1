#include "LED_state.h"
#include "servo.h"
#include "grabber.h"
#include "pickup_dropoff.h"


void setup() {
  // put your setup code here, to run once:
    AFMS.begin(); // Setup motor
    servo_setup();
    LED_setup(); // LEDs initialised
}

void loop() {
  //tests pickup and dropoff things in both orientations
  orientation = 0;
  pickupmine();
  delay_with_LEDs(5000);
  dropoffmine();
  delay_with_LEDs(5000);
  orientation = 1;
  pickupmine();
  delay_with_LEDs(5000);
  dropoffmine();
  delay_with_LEDs(5000);  
}
