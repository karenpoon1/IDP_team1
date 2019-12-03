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
String data;
int a;

void setup() {
    AFMS.begin(); // Setup motor
    
    Serial.begin(9600);

            while(true){
            if (Serial.available() > 0) {
                char c;
                c = Serial.read();
                if (c == 'n') {
//                    Serial.println(a);
                    mine_distances[j] = a;
                    Serial.println(mine_distances[j]);
                    j++;
                    data = "";
                }
                else {
                data += c;
                a = data.toInt();
                }
                if (j == 4){
                  break;
                }
            }
            }
    about_robot_clockwise_90();
    
    move_distance_forward(100, mine_distances[1]); //test
    stop_motors();
    delay(1000);
    move_distance_forward(100, mine_distances[2]); //test
    stop_motors();
    delay(1000);
    move_distance_forward(100, mine_distances[3]); //test
    stop_motors();
    delay(1000);
        
    delay(10000000);
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
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front();
            mine_wall_detect(10); // detect if <10 in front
            previousmillis = LED_call(previousmillis); //LED blinking
            if (mine_wall_detected) {
                mine_wall_detected = false;
                break;
            }
            delay(500);
        }
        stop_motors();
        delay(2000);
                
        pickupmine();

        move_forward(100);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            previousmillis = LED_call(previousmillis);
            detect_front(); //detect wall
            mine_wall_detect(30);
            if (mine_wall_detected) { //if wall detected
                mine_wall_detected = false;
                break;
            }
            delay(500);
        }
        stop_motors();

        about_robot_anticlockwise_45();

        dropoffmine();

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
    }
        
    if (mine_counter > 0 && mine_counter < 7) {
        move_forward(50);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_side(); // detect wall
            previousmillis = LED_call(previousmillis);
            mine_detect(25);
            if (mine_detected) {
                mine_detected = false;
                break;
            }
            delay(500);
        }
        stop_motors();
        delay(2000);

        move_distance_forward(100,10); // arbitrary (or backward)

        about_robot_anticlockwise_90();

        move_distance_forward(100,20);
        
        pickupmine();

        move_distance_backward(100, mine_distances[mine_counter-1] + 80); //- it can't handle this atm
        move_distance_forward(100, 50);
        about_robot_anticlockwise_90();
        move_forward(50);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            previousmillis = LED_call(previousmillis);
            detect_front(); //detect wall
            mine_wall_detect(30); 
            if (mine_wall_detected) { //if wall detected
                mine_wall_detected = false;
                break;
            }
            delay(500);
        }
        
        stop_motors();
        delay(2000);

        about_robot_anticlockwise_45();
        
        dropoffmine();
        
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

        mine_counter++;
}
}
