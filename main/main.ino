#include "LED_state.h"
#include "movement.h"
#include "ultrasonic.h"
#include "servo.h"
#include "homing.h"
#include "movement_set.h"
#include "grabber.h"
#include "pickup_dropoff.h"


int mine_counter;
int mine_distances; //calibrated values in an array

void setup() {
    AFMS.begin(); // Setup motor
    Serial.begin (9600); // Don't really need at last
    servo_setup();
    LED_setup(); // LEDs initialized
    front_ultrasonic_setup();
    side_ultrasonic_setup();
    mine_counter = 0;
    initial_movement();
//    move_distance_backward(100,30);
//    about_robot_clockwise_90();
//    stop_motors();
//    delay(1000000);
}

void loop() {
    if (mine_counter == 0) {
        // now robot is facing direction towards the known mine so it moves forward
        move_forward(100);
        // while loop to detect mine in front, and will stop when mine is ___ cm in front (the distance in front is set by
        // the argument in the "actual detect()" function)
        while (true) {
            detect_front();
            actual_detect(5);
            if (mine_wall_detected) {
                mine_wall_detected = false
                break;
            }
        }
        stop_motors();

        delay(100000); // for testing only

        // flip gripper arm in place
        // detect_mine_orientation();
        // if oriented correctly
            // flip_mine();
        // grip_mine();

        move_forward(100);
        while (true) {
            detect_front(); //detect wall
            actual_detect(15);
            if (mine_wall_detected) { //if wall detected
                mine_wall_detected = false
                break;
            }
        }
        about_robot_anticlockwise_45();

        // drop_mine(); then gripper arm return to rest position
        
        about_robot_clockwise_45();

        // homing to front wall
        about_robot_clockwise_90();
        move_distance_backward(100, 60);
        move_distance_forward(100, 50);

        // moving towards mine in forward direction only
        move_distance_forward(100, mine_distances[mine_counter];

        // homing to left wall
        about_robot_clockwise_90();
        move_distance_backward(100, 40);
    }
    // following navigation sequences are to be added
    else if (mine_counter > 0 && mine_counter < 7) {
        move_forward(50);
        while (true) {
            detect_side(); //detect wall
            mine_detect(15);
            if (mine_detected) { //if wall detected
                mine_detected = false
                break;
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
