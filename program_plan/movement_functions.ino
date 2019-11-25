void pickupmine() {
  //insert pickup code here
  //something to do with angle
  //need to take input from hall sensors
  //use servo to grab
  //lift or flip depending on orientation (variable for flipping)
}
 void dropoffmine() {
  //insert drop off code here
  //if flipped unflip
  mines += 1
}

void homing() {
  //code defining lining up against wall here
}

void endprogram() {
  //insert drive to corner code here
  //if only triggering after 8 mines, could assume from far corner
  noInterrupts();
  while(1) {}
}
