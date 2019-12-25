
void initial_movement() {
    move_distance_backward(10);
    move_distance_forward(10);
    anticlockwise_90();
    move_distance_backward(20);
    }

void after_grip_movement() {
    move_backward();//
    while (true) {//in this loop somehow? check how detect_mine works, is there a delay anywhere?
        detect_mine();
        actual_detect(10);
            if (back_wall_detected) {
                break;
            }
    move_distance_backward();//there's nothing between these statements??? and I can't actually tell how this while loop is supposed to end
    move_distance_forward();
    clockwise_90();
    while (true) {//I don't understand why this loop is repeated twice. is this actually called anywhere?
        detect_mine();
        actual_detect(10);
            if (back_wall_detected) {
                break;
            }
    }
    move_distance_backward();
    move_distance_forward();
    clockwise_90();
    // drop mine - need to include state change
}
void after_drop() {
    anticlockwise_90();
    move_distance_backward();//a lot of these will have lights, just missing arguments
}
