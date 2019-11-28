
void initial_movement() {
    move_distance_backward(10);
    move_distance_forward(10);
    anticlockwise_90();
    move_distance_backward(20);
    }

void after_grip_movement() {
    move_backward();
    while (true) {
        detect_mine();
        actual_detect(10);
            //if (back_wall_detected) { - this is not a defined function!!!
                //break;
            //}
    move_distance_backward(0);//placeholder values - these need an argument
    move_distance_forward(0);
    clockwise_90();
    while (true) {
        detect_mine();
        actual_detect(10);
            //if (back_wall_detected) { this is not a defined function!!!!
                //break;
            //}
    }
    move_distance_backward(0);//placeholder values - these need to take arguments
    move_distance_forward(0);
    clockwise_90();
    // drop mine
    }
}
void after_drop() {
    anticlockwise_90();
    move_distance_backward(0);//placeholder value - this needs an argument!
}
