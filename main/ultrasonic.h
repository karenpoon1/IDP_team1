
#define trigPin 12 // Send waves
#define echoPin 13 // Receive waves
#define led_red 10
#define led_white 11

long distance = 0;
long prev_mine_distance = 0;
bool mine_detected = false;

void front_ultrasonic_setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led_red, OUTPUT);// Do we need these LEDs
    pinMode(led_white, OUTPUT);
}

void detect_mine() {
    long duration;
    prev_mine_distance = distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
}

void actual_detect(int thresh_from_mine) {
    if (prev_mine_distance == 0 || distance == 0) {
        digitalWrite(led_red,LOW);
        digitalWrite(led_white,LOW);
    }
    else if (prev_mine_distance < thresh_from_mine && distance < thresh_from_mine) {
        stop_motors();
        digitalWrite(led_red,HIGH);
        digitalWrite(led_white,LOW);
        mine_detected = true;
    }
    else {
        digitalWrite(led_red,LOW);
        digitalWrite(led_white,HIGH);
    }

    // Serial Monitor output
    if (distance >= 200 || distance <= 0){
        Serial.println("Out of range");
    }
    else {
        Serial.print(distance);
        Serial.println(" cm");
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
//

//void goto_mine() {
//
////    else {
////        digitalWrite(led_red,LOW);
////        digitalWrite(led_green,HIGH);
////    }
////    if (distance >= 200 || distance <= 0){
////        Serial.println("Out of range");
////    }
////    else {
////        Serial.print(distance);
////        Serial.println(" cm");
////    }
////    delay(500);
//}
