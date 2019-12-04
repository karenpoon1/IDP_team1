// When car is at start position, it homes with two walls at the corner, and ends up facing the direction towards the known mine
void initial_movement() {
    move_distance_backward(100, 20);
    // 65 comes from required 50 from table, and half of robot size
    move_distance_forward(100, 45);
    about_robot_anticlockwise_90();
    move_distance_backward(100, 55);
    }
    
