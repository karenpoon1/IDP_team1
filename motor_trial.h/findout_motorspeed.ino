void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
}

void move_forward() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(50);
    motor_left->run(FORWARD);
    motor_right->run(BACKWARD);
    delay(3000);
}

void move_backward() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(50);
    motor_left->run(BACKWARD);
    motor_right->run(FORWARD);
    delay(1000);
}

void clockwise_90() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(FORWARD);
    delay(3896);
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
//    move_forward();
//    stop_motors();
    anticlockwise_90();
    stop_motors();
//     move_forward;
//     clockwise_90;
//     move_forward;
//     clockwise_90;
//     move_forward;
//     clockwise_90;
}
