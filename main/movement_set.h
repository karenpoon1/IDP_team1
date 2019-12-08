// When car is at start position, it homes with two walls at the corner
// and ends with facing the direction towards the known mine
void initial_movement() {
    move_distance_backward(150, 20);
    move_distance_forward(150, 45);
    about_robot_anticlockwise_90();
    move_distance_backward(150, 45);
    }
    
