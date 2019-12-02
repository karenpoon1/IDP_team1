#include "LED_state.h"
#include "movement.h"
#include "ultrasonic.h"
#include "servo.h"
#include "homing.h"
#include "movement_set.h"
#include "grabber.h"
#include "pickup_dropoff.h"

int mine_counter;
int mine_distances[8]; //calibrated values in an array
unsigned long previousmillis;
int j = 0;

void setup() {
    AFMS.begin(); // Setup motor
    
    Serial.begin(9600);
    delay(2000);
    
    while(true) {
    if(Serial.available() > 0) {
        String serIn=Serial.readString();
        int dist = serIn.toInt();
        mine_distances[j] = dist;
        j++;
        move_distance_forward(100, mine_distances[mine_counter]); 
        if (Serial.available() == 0) {
          break;
        }
    }
    }
    Serial.println(mine_distances)
    
    servo_setup();
    LED_setup(); // LEDs initialised
    front_ultrasonic_setup();
    side_ultrasonic_setup();
    mine_counter = 0;
    initial_movement(); // Home and robot faces known mine
    
//    move_distance_forward(100,mine_distances[0]);
}

void loop() {
    if (mine_counter == 0) {
        move_forward(100);
        previousmillis = millis(); //needed for LEDs
        long prev_dist;
        long curr_dist = 0;
        while (true) { // change to counter so it doesnt enter an infinite loop
            prev_dist = curr_dist;
            curr_dist = front_dist();
            previousmillis = LED_call(previousmillis); //LED blinking
            if (mine_detected(10, prev_dist) && mine_detected(10, curr_dist)) {
                break;
            }
            delay(500);
        }
        stop_motors();
        delay(1000);
                
//        pickupmine();

        move_forward(200);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front(); // detect wall
            previousmillis = LED_call(previousmillis);
            actual_detect(30);
            if (mine_wall_detected) { // if wall detected
                mine_wall_detected = false;
                break;
            }
            delay(500);
        }
        
        stop_motors();
        delay(1000);

        about_robot_anticlockwise_45();

        // drop_mine(); then gripper arm return to rest position
//        dropoffmine();

        // the following sequence is robot homing with walls, then going towards the first mine to picked, hardcode!
        about_robot_clockwise_45();

        // homing to front wall
        about_robot_clockwise_90();
        move_distance_backward(100, 60);
        move_distance_forward(100, 50);

        // moving towards mine in forward direction only
        move_distance_forward(100, mine_distances[mine_counter]-20); 

        // homing to left wall
        about_robot_clockwise_90();
        move_distance_backward(100, 40);
        stop_motors();
    }
        
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
        delay(500);
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
