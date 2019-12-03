Adafruit_DCMotor *motor_flip = AFMS.getMotor(3);

void flip_mine() {
    motor_flip->setSpeed(200);
    motor_flip->run(FORWARD);
    delay_with_LEDs(1500);
    motor_flip->setSpeed(0);
}

void backflip_mine() {
    motor_flip->setSpeed(200);
    motor_flip->run(BACKWARD);
    delay_with_LEDs(1800);
    motor_flip->setSpeed(0);
}

void lift_mine() {
    motor_flip->setSpeed(200);
    motor_flip->run(BACKWARD);
    delay_with_LEDs(250);
    motor_flip->setSpeed(100);
}

void lower_mine() {
    motor_flip->setSpeed(200);
    motor_flip->run(FORWARD);
    delay_with_LEDs(100);
    motor_flip->setSpeed(0);
}
