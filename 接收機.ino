#include <IRremote.h>

const int irReceiverPin = 4;
IRrecv irrecv(irReceiverPin);
decode_results results;

IRsend irsend;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)) {
    switch(results.decode_type) {
      case NEC:
        Serial.print("NEC ");
        break;
      case SONY:
        Serial.print("SONY ");
        break;
      case RC5:
        Serial.print("RC5 ");
        break;
      case RC6:
        Serial.print("RC6 ");
        break;
      default:
        Serial.print("Unknown encoding ");
    }
    Serial.print("irCode: ");
    Serial.print(results.value, HEX);
    Serial.print(", bits: ");
    Serial.println(results.bits);
    irrecv.resume();
    Serial.println(results.decode_type);
  }

}