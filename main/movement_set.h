// When car is at start position, it homes with two walls at the corner, and ends up facing the direction towards the known mine
void initial_movement() {
    move_distance_backward(100, 20);
    // 65 comes from required 50 from table, and half of robot size
    move_distance_forward(100, 45);
    about_robot_anticlockwise_90();
    move_distance_backward(100, 30);
    }

// This is after the robot gripped the mine, it should go all the way back to wall 1 and home there once, then return to station
// To know where is wall 1, it either needs to rotate 180 degrees after getting the mine, or it needs another sensor at the back
// so it knows it reaches a wall
void after_grip_movement() {
    move_backward(100);
    while (true) {
        detect_mine();
        actual_detect(10);
            //if (back_wall_detected) { - this is not a defined function!!!
                //break;
            //}
    move_distance_backward(100,10);//placeholder values - these need an argument
    move_distance_forward(100,10);
    clockwise_90();
    while (true) {
        detect_mine();
        actual_detect(10);
            //if (back_wall_detected) { this is not a defined function!!!!
                //break;
            //}
    }
    move_distance_backward(100,10);//placeholder values - these need to take arguments
    move_distance_forward(100,10);
    clockwise_90();
    // drop mine
    }
}

// The position where the robot drops the mine should also imply the robot can then turn 90 degrees, so its faces the right hand
// side wall, and start detecting stuff from its left side sensor
void after_drop() {
    anticlockwise_90();
    move_distance_backward(100, 10);//placeholder value - this needs an argument!
}
