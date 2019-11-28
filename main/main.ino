#include "movement.h"
#include "ultrasonic.h"
#include "initial_movement.h"

int mine_counter;

void setup() {
    AFMS.begin(); // Setup motor
    Serial.begin (9600); // Don't really need at last
    servo_setup();
    LED_setup(); // LED_state - what format - needs 3 states? (flashing orange, flashing red, solid orange)
    front_ultrasonic_setup();
    mine_counter = 0;
    initial_movement();
}

void loop() {
    if (mine_counter == 0) {
        move_forward();
        while (true) {
            detect_mine();
            actual_detect(5);
            if (mine_detected) {
                break;
            }
        }
        stop_motors();

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
