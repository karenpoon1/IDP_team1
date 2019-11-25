void mine_detected {
  int mine_distance;
  //bool closer_mine = false;
  //the function below needs to be changed to however sensors and motor simultaneously worked
  //I can hard code this if needed, e.g.:
  mine_distance = distance;
  //start_motors(speed);
  for (int x = 1; x < 300; x = x + 1){//distance but delay uses time - check speed
    if (distance < mine_distance) {
      //closer_mine = true;
      break;
    }
    if (x == 150) {
      //reverse motors
    }
    delay(10);
  }
  anticlockwise_90();
  //homing will go here
  //another for loop? for distance-5 divided by speed time increments
  //travel, checking distance2 is less than distance-5
  //if not, turning
  move_forward(100, distance-5);
  //hall effect code goes here
  //pickup code goes here
  move_backward(100, distance-5);
  clockwise_90();
}
