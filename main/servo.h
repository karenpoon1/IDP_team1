#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h> 

void servo_setup() {
    int servoPin = 9;
    Servo servo;
    int angle = 0;//current servo angle
    servo.attach(servoPin);
}

void servo_forward (int inputangle) {
    for(angle = 0; angle < inputangle; angle++) {
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
