void pickupmine() {
  //insert pickup code here
}
 void dropoffmine() {
  //insert drop off code here
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
