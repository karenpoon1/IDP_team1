int orientation = 0; //let's have 0 = north, 1 = south - can I use the same for both flip position and orientation detected?
//have it only change when hall effect measured, immediately use that to remember to flip
//so when its referenced in the drop off function, it can be used to assume whether it was flipped

void pickupmine() {
  digitalWrite(redpin, LOW);//solid orange light
  digitalWrite(orangepin, HIGH);
  //both hall sensors are +ve? - get closer until 1 is referenced
  //if its north, orientation = 0
  //if its south, orientation = 1
  //then close jaws all the way - check what this is to hold it firmly
  flip_mine();//this has an inbuilt delay
  delay_with_LEDs(2000);
  servo_grab();//so does this, technically
  if (orientation == 1) {
    backflip_mine();//if orientation = south, flip (small_motor)
  }
  else if (orientation == 0) {
    lift_mine();
    //lift_grabber();//else lift it a bit? so it's not blocking the sensor? - this probably isnt possible
  }
  digitalWrite(orangepin, LOW);
  ledtype = 3;//change light state to blinking red
  //mine has been picked up!
}

void dropoffmine() {
  //this is easier
  if (orientation == 1) {//flip back if necessary - if orientation is 1, else lower a bit
    flip_mine();
  }
  else if (orientation == 0){
    lower_mine();
    //lower_grabber();
  }
  orientation = 0;//set orientation = 0 again
  servo_release();
  //return servo to 0 degrees - or reverse
  ledtype = 1;//change light state to blinking orange
  backflip_mine();
  //lift_grabber();//lift grabber a bit (if possible)  
  //mine has been dropped!
}
