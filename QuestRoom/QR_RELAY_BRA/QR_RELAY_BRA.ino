/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


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
  delay(10000);
  digitalWrite(6, HIGH);
}

void loop() {



}

