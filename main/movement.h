#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_left = AFMS.getMotor(1);
Adafruit_DCMotor *motor_right = AFMS.getMotor(2);

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
    delay(time);
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
    delay(time);
//    delay_with_LEDs(time);
}

void clockwise_90() {
    int timedelay = 5200;
    motor_left->setSpeed(100);
    motor_right->setSpeed(0);
    motor_left->run(FORWARD);
    delay(timedelay);    
//    delay_with_LEDs(13000);
}

void anticlockwise_90() {
    int timedelay = 5200;
    motor_left->setSpeed(100);
    motor_right->setSpeed(0);
    motor_left->run(BACKWARD);
    delay(timedelay);
//    delay_with_LEDs(timedelay);

}

void stop_motors() {
    motor_left->setSpeed(0);
    motor_right->setSpeed(0);
    //delay(100000); delay for tests only
}

//make this proper end - add return to starting box section, then stop
void endrun(void) {
  //stop all programming
  noInterrupts();
  while(1) {}
}
