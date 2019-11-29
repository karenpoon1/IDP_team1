#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "LED_state.h"
#include "servo.h"
//void delay_with_LEDs(int starttime);

//ledtype = 1;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_flip = AFMS.getMotor(1);

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
    delay_with_LEDs(200);
    motor_flip->setSpeed(100);
}

void lower_mine() {
    motor_flip->setSpeed(200);
    motor_flip->run(FORWARD);
    delay_with_LEDs(100);
    motor_flip->setSpeed(0);
}
void setup() {
  AFMS.begin(); // Setup motor
  servo_setup();
  delay_with_LEDs(5000);
  servo_grab();
}

void loop() {
  backflip_mine();
  delay_with_LEDs(5000);
  flip_mine();
  delay_with_LEDs(5000);
  lift_mine();
  delay_with_LEDs(5000);
  lower_mine();
  delay_with_LEDs(5000);
  //delay(10000);
  
  // put your main code here, to run repeatedly:

}
