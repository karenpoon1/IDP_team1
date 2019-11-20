
void setup() {
    Serial.begin (9600);
    AFMS.begin();
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led_red, OUTPUT);
    pinMode(led_green, OUTPUT);

