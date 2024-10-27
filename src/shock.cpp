#include "Arduino.h"

#define SHOCK_PIN 5

uint8_t shock_value = 0;

int shock_alarm_time = 250;

unsigned count = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Start");

  pinMode(SHOCK_PIN, INPUT);
}
void loop() {
  shock_value = digitalRead(SHOCK_PIN);

  if (shock_value == 1) {
    count++;
    Serial.print("shock!");
    Serial.println(count);
  }
}