#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
//void delay_with_LEDs(int starttime);

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_left = AFMS.getMotor(1);
Adafruit_DCMotor *motor_right = AFMS.getMotor(2);
Adafruit_DCMotor *motor_flip = AFMS.getMotor(3);

int speed = 50;

void move_forward(int speed) {
    motor_left->setSpeed(speed);
    motor_right->setSpeed(speed);
    motor_left->run(FORWARD);
    motor_right->run(BACKWARD);
}

void move_distance_forward(int speed, int desired_distance) {
    //desired_distance in cm
    double actual_speed;
    int time;
    actual_speed = speed/12.5; //manual calibration
    time = (desired_distance/actual_speed)*1000;
    motor_left->setSpeed(speed);
    motor_right->setSpeed(speed);
    motor_left->run(FORWARD);
    motor_right->run(BACKWARD);
//    delay_with_LEDs(time);
}
void move_backward(int speed) {
    motor_left->setSpeed(speed);
    motor_right->setSpeed(speed);
    motor_left->run(BACKWARD);
    motor_right->run(FORWARD);
}

void move_distance_backward(int speed, int desired_distance) {
    //desired_distance in cm
    double actual_speed;
    int time;
    actual_speed = speed/12.5; //manual calibration
    time = (desired_distance/actual_speed)*1000;
    motor_left->setSpeed(speed);
    motor_right->setSpeed(speed);
    motor_left->run(BACKWARD);
    motor_right->run(FORWARD);
//    delay_with_LEDs(time);
}

void clockwise_90() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(FORWARD);
//    delay_with_LEDs(13000);
}

void anticlockwise_90() {
    int timedelay = 13000;
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(BACKWARD);
//    delay_with_LEDs(timedelay);

}

void stop_motors() {
    motor_left->setSpeed(0);
    motor_right->setSpeed(0);
    //delay(100000); delay for tests only
}

void flip_mine() {
  //something to do with small motor here
}

void backflip_mine() {
  //reverse of flip mine here
}

//make this proper end - add return to starting box section, then stop
void endrun(void) {
  //stop all programming
  noInterrupts();
  while(1) {}
}

//void loop() {
//    move_forward();
////    stop_motors();
////     anticlockwise_90();
////     stop_motors();
//}
