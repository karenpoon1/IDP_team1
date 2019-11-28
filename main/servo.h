#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h> 
int angle = 0;//current servo angle

void servo_setup() {
    int servoPin = 9;
    Servo servo;
    servo.attach(servoPin);
}

void servo_forward (int inputangle) {
    for(angle = 0; angle < inputangle; angle++) {
        Servo servo;
        servo.write(angle);
        delay(15);                   
    }
}

void servo_backward (int inputangle) {
    for(angle = inputangle; angle > 0; angle--) {
        Servo servo;
        servo.write(angle);           
        delay(15);                               
    }
}
