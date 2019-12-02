#include "LED_state.h"
#include "movement.h"
#include "ultrasonic.h"
#include "servo.h"
#include "homing.h"
#include "movement_set.h"
#include "grabber.h"
#include "pickup_dropoff.h"

int mine_counter;
int mine_distances[8] = {100,100,100,100,100,100,100}; //calibrated values in an array
unsigned long previousmillis;

void setup() {
    AFMS.begin(); // Setup motor
    Serial.begin (9600); // Don't really need at last
    servo_setup();
    LED_setup(); // LEDs initialised
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
        previousmillis = millis();//needed for LEDs
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front();
            actual_detect(5);
            previousmillis = LED_call(previousmillis);//LED blinking
            if (mine_wall_detected) {
                mine_wall_detected = false;
                break;
            }
        }
        stop_motors();
                
        pickupmine();

        move_forward(100);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front(); //detect wall
            previousmillis = LED_call(previousmillis);
            actual_detect(15);
            if (mine_wall_detected) { //if wall detected
                mine_wall_detected = false;
                break;
            }
        }
        stop_motors();

        about_robot_anticlockwise_45();

        // drop_mine(); then gripper arm return to rest position
        dropoffmine();

        // the following sequence is robot homing with walls, then going towards the first mine to picked, hardcode!
        about_robot_clockwise_45();

        // homing to front wall
        about_robot_clockwise_90();
        move_distance_backward(100, 60);
        move_distance_forward(100, 50);

        // moving towards mine in forward direction only
        //move_distance_forward(100, mine_distances[mine_counter]); it cant handle this atm

        // homing to left wall
        about_robot_clockwise_90();
        move_distance_backward(100, 40);
    }
    
    delay(100000); // for testing only
        
    // following navigation sequences are to be added
    if (mine_counter > 0 && mine_counter < 7) {
        move_forward(50);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_side(); //detect wall
            previousmillis = LED_call(previousmillis);
            mine_detect(25);
            if (mine_detected) { //if wall detected
                mine_detected = false;
                break;
            }
        }
        stop_motors();

        move_distance_forward(50,10); // arbitrary (or backward)

        about_robot_anticlockwise_90();
        detect_front();
        detect_front();

        if (curr_side_distance < 30) {
            //continue; - commented out as this statement isn't in a loop
        }
        else {
            // check or go home
        }

        move_forward(50);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front(); //detect wallmi            mine_wall_detect(8);
            if (mine_wall_detected) { //if wall detected
                mine_wall_detected = false;
                break;
            }
        }
        stop_motors();
        pickupmine();
        // flip gripper arm in place
        // detect_mine_orientation();
        // if oriented correctly
            // flip_mine();
        // grip_mine();

        move_distance_backward(100, mine_distances[mine_counter-1] + 60); //- it can't handle this atm
        move_distance_forward(100, 50);
        about_robot_anticlockwise_90();
        move_forward(50);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            previousmillis = LED_call(previousmillis);
            detect_front(); //detect wall
            actual_detect(30); //- what is this???
            if (mine_wall_detected) { //if wall detected
                mine_wall_detected = false;
                break;
            }
        }
        stop_motors();
        about_robot_anticlockwise_45();
        dropoffmine();
        about_robot_clockwise_45();
        about_robot_clockwise_90();
        move_distance_backward(100, 60);
        move_distance_forward(100, 50);

        // moving towards mine in forward direction only
        move_distance_forward(100, mine_distances[mine_counter]);// - it can't handle this atm

        // homing to left wall
        about_robot_clockwise_90();
        move_distance_backward(100, 40);

    mine_counter++;
}
}
