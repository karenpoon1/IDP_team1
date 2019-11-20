
void setup() {
    AFMS.begin();
}

void move_forward(int speed, int desired_distance) {
    double actual_speed;
    int time;
    actual_speed = speed/12.5 //manual calibration
    time = (desired_distance/actual_speed)*1000
    motor_left->setSpeed(speed);
    motor_right->setSpeed(speed);
    motor_left->run(FORWARD);
    motor_right->run(BACKWARD);
    delay(time);
}

void move_backward() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(50);
    motor_left->run(BACKWARD);
    motor_right->run(FORWARD);
    delay(3000);
}

void clockwise_90() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(FORWARD);
    delay(13000);
}

void anticlockwise_90() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(BACKWARD);
    delay(13000);
}

void stop_motors() {
    motor_left->setSpeed(0);
    motor_right->setSpeed(0);
    delay(100000);
}

void loop() {
    move_forward();
//    stop_motors();
//     anticlockwise_90();
//     stop_motors();
}
