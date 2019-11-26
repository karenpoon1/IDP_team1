#include "movement.h"
#include "ultrasonic.h"
#include "initial_movement.h"
int mine_counter = 0;

void setup() {
    AFMS.begin(); // Setup motor
    Serial.begin (9600); // Setup ultrasonic sensor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led_red, OUTPUT);
    pinMode(led_white, OUTPUT);
    mine_counter = 0;
//    initial_movement();
    move_forward();
}

void loop() {
    if (mine_counter == 0) {
//        move_forward();
        while (true) {
            detect_mine();
            actual_detect(5);
                if (mine_detected){
                    break;
                }
        }
        // detect mine orientation 
        // flip / grip mine
        
//        move_forward();
        delay(1000000);
    if (mine_counter > 0 && mine_counter < 7) {
        while (true) {
            }
    }
    mine_counter++;
        
    }
}

//    while (old_mine_distance > 80 && new_mine_distance > 80) {
//        detect_mine();
//        stop_motors();
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
