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
    LED_setup(); // LEDs initialized
    front_ultrasonic_setup();
    mine_counter = 0;
    initial_movement();
}

void loop() {
    if (mine_counter == 0) {
        // now robot is facing direction towards the known mine so it moves forward
        move_forward();
        // while loop to detect mine in front, and will stop when mine is ___ cm in front (the distance in front is set by
        // the argument in the "actual detect()" function)
        while (true) {
            detect_mine();
            actual_detect(5);
            if (mine_detected) {
                break;
            }
        }
        stop_motors();
    }
        // the following is supposed to be a mine pole detection function and mine gripping function, which have to be written
        // detect_mine_orientation();
        // if oriented correctly
        // flip_mine();
        // grip_mine();
        // after_grip_movement(); (in movement_set.h)

    // following navigation sequences are to be added
    if (mine_counter > 0 && mine_counter < 7) {
        while (true) {
            }
    }
    mine_counter++;
}


// the following, im thinking how to check mine forward, but am thinking of a better algorithm which i will discuss with you later
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
