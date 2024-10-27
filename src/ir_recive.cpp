#include <Arduino.h>

#define ir_i 32

uint8_t brightness = 200;
int counter = 0;

void setup() {
  pinMode(ir_i, INPUT);
  Serial.begin(115200);
}

void loop() {

  int s = Signal(ir_i);
  Serial.print("signal:");
  Serial.print(s);
  Serial.print("      counter:");
  Serial.println(counter);

  counter++;
}

int Signal(int In) {
 
  int tot = 0;

  for (int i = 0; i < 100; i++) {
    tot += analogRead(In);
    delay(10);
  }
  return tot;
}