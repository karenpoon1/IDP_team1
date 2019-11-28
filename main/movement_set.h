// When car is at start position, it homes with two walls at the corner, and ends up facing the direction towards the known mine
void initial_movement() {
    move_distance_backward(10);
    move_distance_forward(10);
    anticlockwise_90();
    move_distance_backward(20); //check Friday if this actually means we're on the line - is a microswitch necessary?
    }

// This is after the robot gripped the mine, it should go all the way back to wall 1 and home there once, then return to station
// To know where is wall 1, it either needs to rotate 180 degrees after getting the mine, or it needs another sensor at the back
// so it knows it reaches a wall
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

// The position where the robot drops the mine should also imply the robot can then turn 90 degrees, so its faces the right hand
// side wall, and start detecting stuff from its left side sensor
void after_drop() {
    anticlockwise_90();
    move_distance_backward(0);//placeholder value - this needs an argument!
}
