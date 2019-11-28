#include "movement.h"
#include "ultrasonic.h"
//#include "initial_movement.h" - this doesn't currently exist
#include "LED_state.h"
#include "servo.h"
#include "homing.h"
#include "movement_set.h"
#include "pickup_dropoff.h"
#include "side_ultrasonic.h"

int mine_counter;


void setup() {
    AFMS.begin(); // Setup motor
    Serial.begin (9600); // Don't really need at last
    servo_setup();
    //pinMode (orangepin, OUTPUT);
    //pinMode (redpin, OUTPUT);
    LED_setup(); // LEDs initialized
    front_ultrasonic_setup();
    mine_counter = 0;
    //initial_movement();
}

void loop() {
  if (mine_counter == 0) {
    //move_forward();
    while (true) {
      detect_mine();
      actual_detect(5);
      if (mine_detected){
        break;
      }
    }
    //detect mine orientation 
    //flip / grip mine
    //move_forward();
    delay(1000000);
    if (mine_counter > 0 && mine_counter < 7) {
      while (true) {
        //something here?
      }
    }
    mine_counter++;
  }
  move_forward();
  while (true) {
    detect_mine();
    //while (old_mine_distance > 80 && new_mine_distance > 80) {
    //detect_mine();
  }
  //stop_motors();
}
//    stop_motors();
//    delay(1000000);
//}
//}
//     check_mine_forward();
//     mine_counter++
//     if (mine_counter == 7) {
//         anticlockwise_90();
//         homing_wall_left();
//         move_distance_forward(230);
//         clockwise_90();
//         move_distance_forward(20);
//         // Return to start position
