
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);

Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

void motorforward() {
  myMotor1->setSpeed(150);
  myMotor1->run(FORWARD);

  myMotor2->setSpeed(150);
  myMotor2->run(FORWARD);
  delay(100)
}

void motorbackward() {
  myMotor1->setSpeed(150);
  myMotor1->run(BACKWARD);

  myMotor2->setSpeed(150);
  myMotor2->run(BACKWARD);
  delay(100)
}
void motorturnanti() {
  myMotor1->setSpeed(150);
  myMotor1->run(FORWARD);

  myMotor2->setSpeed(150);
  myMotor2->run(BACKWARD);
  delay(100)
}
void motorturnclock() {
  myMotor1->setSpeed(150);
  myMotor1->run(BACKWARD);

  myMotor2->setSpeed(150);
  myMotor2->run(FORWARD);
  delay(100)
}
void setup() {
  // put your setup code here, to run once:
    AFMS.begin();
    myMotor1->setSpeed(150);
    myMotor2->setSpeed(150);
}

void loop() {
  // put your main code here, to run repeatedly:
  motorturnanti();
  motorforward();
  motorturnanti();
  motorforward();
  motorturnanti();
  motorforward();
  motorturnanti();
  motorforward();
}
