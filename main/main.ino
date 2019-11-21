
void setup() {
    AFMS.begin(); // Setup motor
    Serial.begin (9600); // Setup ultrasonic sensor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led_red, OUTPUT);
    pinMode(led_green, OUTPUT);
    move_forward();

void loop() {
    ultrasonic();