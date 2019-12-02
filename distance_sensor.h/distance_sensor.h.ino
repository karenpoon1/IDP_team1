#define trigPin 13 //send waves
#define echoPin 12 //receive waves
//#define led_red 11
//#define led_green 10

void setup() {
    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
//     pinMode(led_red, OUTPUT);
//     pinMode(led_green, OUTPUT);
}

void loop() {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1; // Assume speed of sound 340m/s
//     if (distance < 4) {  // This is where the LED On/Off happens
//         digitalWrite(led_red,HIGH); // When the Red condition is met, the Green LED should turn off
//         digitalWrite(led_green,LOW);
//     }
//     else {
//         digitalWrite(led_red,LOW);
//         digitalWrite(led_green,HIGH);
//    }
//    if (distance >= 200 || distance <= 0){
//        Serial.println("Out of range");
//    }
//    else {
        Serial.print(distance);
        Serial.println(" cm");
//    }
    delay(500);
}
