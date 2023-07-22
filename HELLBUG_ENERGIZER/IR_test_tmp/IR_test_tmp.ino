#include <IRremote.h>
int RECV_PIN = 7;
int IRdata;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    IRdata = results.value;
    Serial.println(IRdata);
    Serial.print("HEX:");
    Serial.println(IRdata, HEX);
    Serial.print("DEC:");
    Serial.println(IRdata, DEC);
    irrecv.resume();
       } 
  }
