#include <Servo.h> 
int servoPin = 9;
Servo servo;  
int angle = 0;   // servo position in degrees 
 
void setup() { 
    servo.attach(servoPin); 
    for(angle = 0; angle < 20; angle++) {                                
        servo.write(angle);               
        delay(15);                   
    }
} 
     
void loop() {
  // put your main code here, to run repeatedly:

}
