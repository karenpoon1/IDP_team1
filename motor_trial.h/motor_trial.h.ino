#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);

Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  myMotor1->setSpeed(150);
  myMotor1->run(FORWARD);

  myMotor2->setSpeed(150);
  myMotor2->run(FORWARD);
}

void loop() {
  // put your main code here, to run repeatedly:

}
