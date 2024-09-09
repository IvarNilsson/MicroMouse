#include <Arduino.h>

#define Serial Serial

const int ledPin_0 = 26;
const int ledPin_1 = 27;

void setup() {
  pinMode(ledPin_0, OUTPUT);
  pinMode(ledPin_1, OUTPUT);
}

void loop() {
  digitalWrite(ledPin_0, 1);
  delay(500);
  digitalWrite(ledPin_0, 0);
  delay(500);
  digitalWrite(ledPin_1, 1);
  delay(1000);
  digitalWrite(ledPin_1, 0);
  delay(1000);
}