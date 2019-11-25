void setup() {
  // put your setup code here, to run once:
  int mines = 0;
  motor_setup();
  move_distance_forward(100,15);
  anticlockwise_90();
  //homing here?
  ultrasonic2();//the forward one
  motor_start(100);
  while (distance2 > 5) {//adjust for actual separation needed for pickup
    delay(10);
  }
  stop_motors();
  pickupmine();
  wall_distance = (int)distance;
  move_distance_forward(100, (wall_distance-5));
  anticlockwise_90();
  move_distance_forward(100,10);
  dropoffmine();
  //homing and turn
}

void loop() {
  // starting position is on line, facing down
  if (mines = 8) {
    ultrasonic2();
    motor_start(100);
    while 
  }
}
