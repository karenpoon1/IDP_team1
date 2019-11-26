#include "movement.h"
#include "ultrasonic.h"
#include "initial_movement.h"
int mine_counter;

void setup() {
    AFMS.begin(); // Setup motor
    Serial.begin (9600); // Setup ultrasonic sensor
    servo_setup();
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led_red, OUTPUT);//do we need these LEDs
    pinMode(led_white, OUTPUT);
    mine_counter = 0;
//    initial_movement();
//    move_forward();
}

void loop() {
    move_forward();
    while (true) {
      detect_mine();
//    while (old_mine_distance > 80 && new_mine_distance > 80) {
//        detect_mine();
    }
//        stop_motors();

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
