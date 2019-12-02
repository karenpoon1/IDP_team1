// front ultrasonic sensor
#define front_trigPin 11 // Send waves
#define front_echoPin 10 // Receive waves

// side ultrasonic sensor
#define side_trigPin 13
#define side_echoPin 12

void front_ultrasonic_setup() {
    pinMode(front_trigPin, OUTPUT);
    pinMode(front_echoPin, INPUT);
}


void side_ultrasonic_setup() {
    pinMode(side_trigPin, OUTPUT);
    pinMode(side_echoPin, INPUT);
}


long detect_ultrasonic(int trig_pin, int echo_pin) {
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    long duration = pulseIn(echo_pin, HIGH);
    long distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
    return distance;
}


long front_dist() {
    return detect_ultrasonic(front_trigPin, front_echoPin);
}


void side_dist() {
    detect_ultrasonic(side_trigPin, side_echoPin);
}


bool is_reading_reliable(int dist) {
    return dist != 0;
}


bool mine_detected(int thresh_from_mine, int dist) {
    return is_reading_reliable(dist) && dist < thresh_from_mine;
}
