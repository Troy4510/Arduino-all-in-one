/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

IRsend irsend;
int i;
void setup()
{
  
  pinMode(6,OUTPUT);
   for (int i = 0; i < 10; i++) {
    digitalWrite(6, LOW);
    delay (random(10, 150));
    digitalWrite(6, HIGH);
    delay (random(10, 150));
  }
  digitalWrite(6, LOW);
  irsend.sendNEC(0x926D00FF, 32);
  delay(30000);
  irsend.sendNEC(0x926D2AD5, 32);
  delay(15000);
  irsend.sendNEC(0x926D00FF, 32);
  digitalWrite(6, HIGH);
}

void loop() {
}


