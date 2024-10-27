#include <Arduino.h>

#define ir_o 33
#define ir_i 32
#define transmitt_en 13

uint8_t brightness = 200;
int counter = 0;

void setup() {
  pinMode(ir_o, OUTPUT);
  pinMode(ir_i, INPUT);
  pinMode(transmitt_en, INPUT);
  Serial.begin(115200);
}

void loop() {

  if (digitalRead(transmitt_en) == 1) {
    digitalWrite(ir_o, 1);
  } else {
    digitalWrite(ir_o, 0);
  }

  int tot = 0;
  for (int i = 0; i < 100; i++) {
    tot += analogRead(ir_i);
    delay(10);
  }

  Serial.print("signal:");
  Serial.print(tot);
  Serial.print("      counter:");
  Serial.println(counter);

  counter++;
}
