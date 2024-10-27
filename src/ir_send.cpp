#include <Arduino.h>
#include <IRremote.h>

int ir_send_pin = 33;
int ir_recive_pin = 32;
int ir_send_en_pin = 13;

IRsend irsend;

int counter = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ir_send_en_pin, INPUT);

  // IrSender.begin(ir_send_pin);
  pinMode(ir_send_pin, OUTPUT);
  pinMode(ir_recive_pin, INPUT);
}

void loop() {

  if (digitalRead(ir_send_en_pin) == 1) {
    // Serial.println("SENDING!");
    // unsigned long code = 10069420731;
    // IrSender.sendNEC(0xFF00FF00, 32);
    digitalWrite(ir_send_pin, 1);
    // delay(100);
  } else {
    digitalWrite(ir_send_pin, 0);
  }

  int tot = 0;
  for (int i = 0; i < 30; i++) {
    tot += analogRead(ir_recive_pin);
    delay(10);
  }

  Serial.print("signal:");
  Serial.print(tot);
  Serial.print("      counter:");
  Serial.println(counter);

  counter++;
}
