#include <Arduino.h>

#define RED_LED 21
#define GREEN_LED 38

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  delay(1000);
  Serial.println("Hello, World! From ESP32-S3");
}

void loop() {
  Serial.println("Hello, World! :)");
  digitalWrite(RED_LED, 1);
  delay(1000);
  digitalWrite(GREEN_LED, 1);
  delay(1000);
  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 0);
  delay(1000);
}
