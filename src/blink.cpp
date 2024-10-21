#include <Arduino.h>

#define Serial Serial

const int ledPin_0 = 38;

void setup() {
  pinMode(ledPin_0, OUTPUT);
  delay(500);
}

void loop() {
  digitalWrite(ledPin_0, 1);
  delay(1000);
  digitalWrite(ledPin_0, 0);
  delay(500);
}