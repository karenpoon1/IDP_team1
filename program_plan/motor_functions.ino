#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h> 

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_left = AFMS.getMotor(1);
Adafruit_DCMotor *motor_right = AFMS.getMotor(2);

     
     

void motors_setup () {
   AFMS.begin(); // Setup motor
   int servoPin = 9;
   Servo servo;  
   int angle = 0;//current servo angle
   servo.attach(servoPin);
   //include other motor & servo code here when available
}

void servo_forward (int inputangle) {
  for(angle = 0; angle < inputangle; angle++)  {                                  
        servo.write(angle);               
        delay(15);                   
      } 
}

void servo_backward (int inputangle) {
  for(angle = inputangle; angle > 0; angle--) {
        servo.write(angle);           
        delay(15);                               
  }
            
}

void motor_start (int speed) {
    motor_left->setSpeed(speed);
    motor_right->setSpeed(speed);
    motor_left->run(FORWARD); //check directions for these are the same
    motor_right->run(BACKWARD);
}

void stop_motors() {
    motor_left->setSpeed(0);
    motor_right->setSpeed(0);
    //delay(100000); delay for tests only
}

void move_distance_forward(int speed, int desired_distance) {
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
void move_backward(int speed) {
    motor_left->setSpeed(speed);
    motor_right->setSpeed(speed);
    motor_left->run(BACKWARD);
    motor_right->run(FORWARD);
    delay(3000);
}

void clockwise_90() {
    motor_left->setSpeed(50);//change these speeds?
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
