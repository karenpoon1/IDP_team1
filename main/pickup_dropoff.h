int orientation = 0; //let's have 0 = north, 1 = south - can I use the same for both flip position and orientation detected?
//have it only change when hall effect measured, immediately use that to remember to flip
//so when its referenced in the drop off function, it can be used to assume whether it was flipped

void pickupmine() {
  //assuming reasonable distance from mine which is basically in front
  //lower_grabber();
  //both hall sensors are +ve? - get closer until 1 is referenced
  //if its north, orientation = 0
  //if its south, orienntation = 1
  //then close jaws all the way - check what this is to hold it firmly
  servo_grab();
  if (orientation = 1) {
    flip_mine();//if orientation = south, flip (small_motor)
  }
  else {
    lift_grabber();//else lift it a bit? so it's not blocking the sensor?
  }
  ledtype = 3;//change light state to blinking red
  //mine has been picked up!
}

void dropoffmine() {
  //this is easier
  if (orientation = 1) {//flip back if necessary - if orientation is 1, else lower a bit
    backflip_mine();
  }
  else {
    lower_grabber();
  }
  orientation = 0;//set orientation = 0 again
  servo_release();
  //return servo to 0 degrees - or reverse
  ledtype = 1;//change light state to blinking orange
  lift_grabber();//lift grabber a bit (if possible)  
  //mine has been dropped!
}
