#include "preambles.h"

void setup() {
  pinMode(RELAY, OUTPUT);
  
  initialize();
}

void loop() {
  mainApp();
}
