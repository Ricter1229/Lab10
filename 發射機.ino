#include <IRremote.h>

IRsend irsend;

void setup() {}

void loop() {
  irsend.sendNEC(0x06050375, 32);
}