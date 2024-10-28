#include "Arduino.h"

const int btnPin = 18;
const int ledPin = 19;

void setup() {
  pinMode(btnPin, INPUT);
  pinMode(ledPin, OUTPUT);
  delay(500);
}

void loop() {
  if (digitalRead(btnPin) == 1) {
    digitalWrite(ledPin, 1);
  } else {
    digitalWrite(ledPin, 0);
  }
  delay(100);
}
