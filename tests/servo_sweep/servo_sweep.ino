    /*
    Adafruit Arduino - Lesson 14. Sweep
    */
     
    #include <Servo.h> 
     
    int servoPin = 9;
     
    Servo servo;  
     
    int angle = 45;   // servo position in degrees 
     
    void setup() 
    { 
      servo.attach(servoPin); 
      for(angle = 0; angle < 75; angle++)  
      {                                  
        servo.write(angle);               
        delay(15);                   
      } 
    } 
     
     
    void loop() 
    { 
      // scan from 0 to 175 degrees
      //for(angle = 30; angle < 75; angle++)  
      //{                                  
        //servo.write(angle);               
        //delay(15);                   
      //} 
      //delay (5000);
      // now scan back from 175 to 0 degrees
      for(angle = 75; angle > 20; angle--)    
      {                                
        servo.write(angle);           
        delay(15);       
      } 
      delay (5000);
    } 
