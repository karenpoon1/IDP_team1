#define trigPin1 12 // Send waves
#define echoPin1 13 // Receive waves
//#define led_red 11
//#define led_green 10

long new_reading 240;

long ultrasonic1() {
    long duration, distance;
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin1, HIGH);
    distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
    old_reading = new_reading;
    new_reading = distance;
    return distance;
}

long ultrasonic2() {
    long duration, distance;
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration = pulseIn(echoPin2, HIGH);
    distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
    old_reading = new_reading;
    new_reading = distance;
    return distance;
}
//include microswitch code here
