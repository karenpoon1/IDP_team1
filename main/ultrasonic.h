
#define trigPin 12 // Send waves
#define echoPin 13 // Receive waves
#define led_red 11
#define led_green 10

long new_reading 240;

void ultrasonic1() {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
    old_reading = new_reading;
    new_reading = distance;

    if (distance < 80) {  // This is where the LED On/Off happens
        digitalWrite(led_red,HIGH); // When the Red condition is met, the Green LED should turn off
        digitalWrite(led_green,LOW);
        stop_motors();
    }
//    else {
//        digitalWrite(led_red,LOW);
//        digitalWrite(led_green,HIGH);
//    }
//    if (distance >= 200 || distance <= 0){
//        Serial.println("Out of range");
//    }
//    else {
//        Serial.print(distance);
//        Serial.println(" cm");
//    }
//    delay(500);
}