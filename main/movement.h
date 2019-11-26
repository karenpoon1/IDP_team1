#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_left = AFMS.getMotor(1);
Adafruit_DCMotor *motor_right = AFMS.getMotor(2);

int speed = 50;

void move_forward() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(50);
    motor_left->run(FORWARD);
    motor_right->run(BACKWARD);
}

void move_distance_forward(int desired_distance) {
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
}
void move_backward() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(50);
    motor_left->run(BACKWARD);
    motor_right->run(FORWARD);
}

void move_distance_backward(int desired_distance) {
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
}

void clockwise_90() {
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(FORWARD);
    delay(13000);
}

void anticlockwise_90() {
    int timedelay = 13000;
    motor_left->setSpeed(50);
    motor_right->setSpeed(0);
    motor_left->run(BACKWARD);
    unsigned long startturn = millis();
    while (true) {
      unsigned long currentMillis = millis();
      if (currentMillis - startturn >= timedelay) {
        //turn LED off?
        break
      }
      else if (currentMillis - previousMillis >= 500) {
            previousMillis = currentMillis;

      }
      //need to factor in which led is on - flashing orange, flashing red, continuous orange
    }
    //measure millis at time
    //while loop less than delay time
    //if millis 0.5 s from last change
    //flip input
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
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

//void loop() {
//    move_forward();
////    stop_motors();
////     anticlockwise_90();
////     stop_motors();
//}
