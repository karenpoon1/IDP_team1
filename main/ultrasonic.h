
#define trigPin 12 // Send waves
#define echoPin 13 // Receive waves
#define led_red 10
#define led_white 11

//long old_mine_distance = 240;
//long new_mine_distance = 240;
//long second_old_mine_distance;
//long second_new_mine_distance;

void detect_mine() {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
    
    if (distance == 0) {
        digitalWrite(led_red,LOW);
        digitalWrite(led_white,LOW);
    }
    
    else if (distance < 30) {
        stop_motors();
        digitalWrite(led_red,HIGH);
        digitalWrite(led_white,LOW);
    }
    else {
        digitalWrite(led_red,LOW);
        digitalWrite(led_white,HIGH);
    }
    if (distance >= 200 || distance <= 0){
//        stop_motors();
        Serial.println("Out of range");
    }
    else {
        Serial.print(distance);
        Serial.println(" cm");
    }
    delay(500);
//    old_mine_distance = new_mine_distance;
//    new_mine_distance = distance;
//    Serial.print(distance);
}

//if (new_mine_distance < 80) {  // This is where the LED On/Off happens
//    digitalWrite(led_red,HIGH); // When the Red condition is met, the Green LED should turn off
//    digitalWrite(led_green,LOW);
//    stop_motors();
//    check_mine_forward();
//    goto_mine();
//}

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
//
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
