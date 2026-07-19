#include <Arduino.h>
//https://github.com/Richard-Gemmell/teensy4_i2c

// put function declarations here:
unsigned long last_mosfet_time = 0;  // declare these at the top
const unsigned long mosfet_delay = 10;
unsigned long current_time = millis();
unsigned long mosfet_delta = 0;

const int high_side_button = 34;
const int low_side_button = 33;
const int high_side = 38;
const int low_side = 37;
const int debug_led = 39;
int p_state;
int n_state;
int p_state_last;
int n_state_last;

void setup() {
  delay(500);
  pinMode(debug_led, OUTPUT);
  digitalWrite (debug_led, HIGH);
  delay(250);
  digitalWrite (debug_led, LOW);
  delay(250);

  pinMode(high_side_button, INPUT);
  pinMode(low_side_button, INPUT);
  pinMode(high_side, OUTPUT);
  pinMode(low_side, OUTPUT);
  delay(500);
  // for (int i = 0; i < 42; i++) {
  //  digitalWrite (i, LOW);
  //}
  digitalWrite (debug_led, HIGH);
  delay(250);
  digitalWrite (debug_led, LOW);
  delay(250);
  p_state = digitalRead(high_side_button); 
  n_state = digitalRead(low_side_button); 
  p_state_last = p_state;
  n_state_last = n_state;

  Serial.begin (9600);
}

void loop() {
  current_time = millis();
  mosfet_delta = current_time - last_mosfet_time;
  p_state = digitalRead(high_side_button); 
  n_state = digitalRead(low_side_button); 
  if ((p_state != p_state_last) and ((mosfet_delta > mosfet_delay))) {
    if (p_state == 1) {
    digitalWrite(high_side, HIGH);
    } else {
      digitalWrite(high_side, LOW);
    }
    p_state_last = p_state;
  }
  if ((n_state != n_state_last) and (p_state == 1) and ((mosfet_delta > mosfet_delay))) {
    if (n_state == 1) {
      digitalWrite(low_side, HIGH);
    } else {
      digitalWrite(low_side, LOW);
    }
    n_state_last = n_state;
  } else if ((n_state != 0) and (p_state == 0) and ((mosfet_delta > mosfet_delay))) {
    digitalWrite(low_side, LOW);
    n_state_last = 0;
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}