
// front ultrasonic sensor
#define front_trigPin 11 // Send waves
#define front_echoPin 10 // Receive waves

// side ultrasonic sensor
#define side_trigPin 13
#define side_echoPin 12

long curr_front_distance = 0;
long prev_front_distance = 0;
bool mine_wall_detected = false;

long curr_side_distance = 0;
long prev_side_distance = 0;
bool mine_detected = false;

void front_ultrasonic_setup() {
    pinMode(front_trigPin, OUTPUT);
    pinMode(front_echoPin, INPUT);
}

void side_ultrasonic_setup() {
    pinMode(side_trigPin, OUTPUT);
    pinMode(side_echoPin, INPUT);
}

void detect_front() {
    long duration;
    prev_front_distance = curr_front_distance;
    digitalWrite(front_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(front_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(front_trigPin, LOW);
    duration = pulseIn(front_echoPin, HIGH);
    curr_front_distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
}

void actual_detect(int thresh_from_mine) {
    if (prev_front_distance == 0 || curr_front_distance == 0) {
        return;
    }
    else if (prev_front_distance < thresh_from_mine && curr_front_distance < thresh_from_mine) {
        mine_wall_detected = true;
        prev_front_distance = 0;
        curr_front_distance = 0;
    }
    else {
        return;
    }

    // Serial Monitor output
    if (curr_front_distance >= 200 || curr_front_distance <= 0){
        Serial.println("Out of range");
    }
    else {
        Serial.print(curr_front_distance);
        Serial.println(" cm");
    }
    
    delay(500);
}

void detect_side() {
    long duration;
    prev_side_distance = curr_side_distance;
    digitalWrite(side_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(side_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(side_trigPin, LOW);
    duration = pulseIn(side_echoPin, HIGH);
    curr_side_distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
}

void mine_detect(int thresh_from_mine) {
    if (prev_side_distance == 0 || curr_side_distance == 0) {
        return;
    }
    else if (prev_side_distance < thresh_from_mine && curr_side_distance < thresh_from_mine) {
        mine_detected = true;
        prev_front_distance = 0;
        curr_front_distance = 0;
    }
    else {
        return;
    }
    delay(500);
}

//void check_mine_forward() {
//    move_forward();
//    int counter 0;
//    while (counter<50) { // Counter to calibrate distance to move
//        detect_mine();
//        if (second_old_mine_distance < new_mine_distance &&
//        second_new_mine_distance < new_mine_distance) {
//            stop_motors();
//        else {
//            stop_motors();
//            move_backward();
//        }
//        counter++
//        delay(10)
//
//}
