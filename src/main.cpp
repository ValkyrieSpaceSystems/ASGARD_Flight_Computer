#include <Arduino.h>

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 42; i++) {
    digitalWrite (i, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println("result");
  delay(2000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}