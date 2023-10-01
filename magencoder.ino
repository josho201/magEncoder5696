#include "magEncoder5696.h"


magEncoder5696 encoder1(A0, A2); 
double lastangle = 0;
double lastlap = 0;

void setup() {
  // Initialize serial communication for debugging
  encoder1.begin();
  Serial.begin(9600);
}

void loop() {

  double angle = encoder1.getAngle();
  double vueltas = encoder1.getPosition();
  
  if(abs(angle - lastangle) > 0.5 || abs(lastlap - vueltas)> 0.01){
    Serial.println("Vueltas: " + String(vueltas) + " Angulo: " + String(angle));
    lastangle = angle;
    lastlap = vueltas;
  }
  // Read sensor values from the analog pins

  
}

