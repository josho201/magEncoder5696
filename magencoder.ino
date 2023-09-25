#include "magEncoder5696.h"


magEncoder5696 encoder1(A0, A2); 

void setup() {
  // Initialize serial communication for debugging
  encoder1.begin();
  Serial.begin(9600);
}

void loop() {
  
  double angle = encoder1.getPosition();
  Serial.println(angle);
  // Read sensor values from the analog pins

  
  
}

