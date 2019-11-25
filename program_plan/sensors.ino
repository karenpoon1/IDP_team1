#define trigPin 12 // Send waves
#define echoPin 13 // Receive waves
//#define led_red 11
//#define led_green 10

long new_reading = 240;

long ultrasonic1() {
    long duration, distance, old_reading;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
    old_reading = new_reading;
    new_reading = distance;
    return distance;
}

//include microswitch code here
