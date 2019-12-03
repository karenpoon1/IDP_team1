//#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h> 
int angle = 0;//current servo angle
int servoPin = 8;
Servo servo;

void servo_setup() {
    servo.attach(servoPin);
    for(angle = 0; angle < 90; angle++)  {                                  
        servo.write(angle);               
        delay(15);                   
    } 
}

void servo_release () {
    for(angle = 20; angle < 90; angle++) {
        //Servo servo;
        servo.write(angle);
        delay(15);                   
    }
}

void servo_grab () {
    for(angle = 90; angle > 20; angle--) {
        //Servo servo;
        servo.write(angle);           
        delay(15);                               
    }
}

void setup() {
  // put your setup code here, to run once:
  servo_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  servo_grab();
  delay(1000);
  servo_release();
  delay(1000);
}
