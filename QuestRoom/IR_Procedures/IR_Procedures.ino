/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

IRsend irsend;

void setup()
{
}

void loop() {

  irsend.sendNEC(0x807F8877, 32);
  delay(1000);
  irsend.sendNEC(0x807F08F7, 32);
  delay(1000);


}

