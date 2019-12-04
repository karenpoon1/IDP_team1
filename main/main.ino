#include "LED_state.h"
#include "movement.h"
#include "ultrasonic.h"
#include "servo.h"
#include "movement_set.h"
#include "grabber.h"
#include "pickup_dropoff.h"

int mine_counter = 0;//number of mines picked up
int mine_distances[8]; //calibrated values in an array
unsigned long previousmillis;//used to calibrate LED timing
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
//                if (j == 3){ 
                if (c == 'o'){
                  break;
                }
            }
            }
    delay(5000);
    servo_setup();
    LED_setup(); // LEDs initialised
    front_ultrasonic_setup();//setup ultrasonic sensors
    side_ultrasonic_setup();
    initial_movement(); // Home and robot faces known mine
    
//    move_distance_forward(100,mine_distances[0]);
}

void loop() {
    if (mine_counter == 0) {//finding the mine on the line
        move_forward(100);
        previousmillis = millis(); //needed for LEDs
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front();
            mine_wall_detect(20); // detect if <10 in front
            previousmillis = LED_call(previousmillis); //LED blinking
            if (mine_wall_detected) {
                mine_wall_detected = false;
                break;
            }
        }
        stop_motors();
        delay(2000);
        move_distance_forward(100,10);
        stop_motors();
        delay(2000);
                
        pickupmine();
        delay(5000);
        move_forward(100);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front(); //detect wall
            mine_wall_detect(15);
            previousmillis = LED_call(previousmillis);
            if (mine_wall_detected) { //if wall detected
                mine_wall_detected = false;
                break;
            }
        }
        
        stop_motors();

        about_robot_anticlockwise_45();
        stop_motors();
        dropoffmine();
        delay(4000);
        // the following sequence is robot homing with walls, then going towards the first mine to picked, hardcode!
        about_robot_clockwise_45();
        stop_motors();
        delay(2000);
        // homing to front wall
        about_robot_clockwise_90();
        move_distance_backward(100, 60);
        move_distance_forward(100, 50);

        // moving towards mine in forward direction only
        move_distance_forward(100, mine_distances[mine_counter]-25); 

        // homing to left wall
        about_robot_clockwise_90();
        move_distance_backward(100, 60);
    }
        
    if (mine_counter > 0 && mine_counter < 8) {
        move_forward(50);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_side(); // detect wall
            mine_detect(25);
            previousmillis = LED_call(previousmillis);
            if (mine_detected) {
                mine_detected = false;
                break;
            }
        }
        stop_motors();
        delay(2000);

        move_distance_forward(100,10); // arbitrary (or backward)

        about_robot_anticlockwise_90();

        move_distance_backward(100,20);

        stop_motors();
        delay(2000);
        
        pickupmine();

        move_distance_backward(100, mine_distances[mine_counter-1] + 80); //- it can't handle this atm
        move_distance_forward(100, 50);
        about_robot_anticlockwise_90();
        move_forward(50);
        previousmillis = millis();
        while (true) { // change to counter so it doesnt enter an infinite loop
            detect_front(); //detect wall
            mine_wall_detect(30); 
            previousmillis = LED_call(previousmillis);
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
    }
    if (mine_counter == 8) {
        stop_motors();
        noInterrupts();
        while(1) {}//this stalls everything - could expand to try to navigate back to beginning
    }
    mine_counter++;
}
