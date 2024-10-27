#include <Arduino.h>

#define ir_o 33
#define ir_i 32
#define Tr1 25

int counter = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ir_o, OUTPUT);
  pinMode(ir_i, INPUT);
  pinMode(Tr1, INPUT);
}

void loop() {
  digitalWrite(ir_o, 1);

  int s = Signal(Tr1);
  Serial.print("signal:");
  Serial.print(s);
  Serial.print("      counter:");
  Serial.println(counter);

  counter++;
}

int Signal(int In) {
  int C = 1023; // max analog read value

  int tot = 0;

  for (int i = 0; i < 100; i++) {
    tot += analogRead(In);
    delay(10);
  }
  return tot;
}