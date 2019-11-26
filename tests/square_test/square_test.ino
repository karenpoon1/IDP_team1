#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_left = AFMS.getMotor(1);
Adafruit_DCMotor *motor_right = AFMS.getMotor(2);

void setup() {
    AFMS.begin();
}

void move_forward() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(50);
    motor_left->run(FORWARD);
    motor_right->run(BACKWARD);
    delay(5000);
}

void move_backward() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(50);
    motor_left->run(BACKWARD);
    motor_right->run(FORWARD);
    delay(5000);
}

void clockwise_90() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(FORWARD);
    delay(10600);
}

void anticlockwise_90() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(BACKWARD);
    delay(12000);
}

void stop_motors() {
    motor_left->setSpeed(0);
    motor_right->setSpeed(0);
    delay(100000);
}

void loop() {
    move_forward();
    clockwise_90();

//     stop_motors();

}
