#include <IRremote.h>
IRsend irsend;
int i;
char inByte;
boolean RedL = false;
boolean BaseM = false;
boolean MainL = false;
void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT); //свет и бра
  pinMode(7, OUTPUT); //красная лампа
  pinMode(8, OUTPUT); //вх.дверь
  pinMode(9, OUTPUT); //свет подвал
  pinMode(10, OUTPUT);//дверь с/у
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}
void loop() {
  if (Serial.available() > 0) {
    inByte = Serial.read();
  }
  else inByte = '0';
  switch (inByte) {              //реакция на входящие сигналы
    case '1':
      MainDoor();
      CleanChannel();
      break;
    case '2':
      Blink();
      CleanChannel();
      break;
    case '3':
      DVDplay();
      CleanChannel();
      break;
    case '4':
      BathLock();
      CleanChannel();
      break;
    case '5':
      RedLamp();
      CleanChannel();
      break;
    case '6':
      Reset();
      CleanChannel();
      break;
    case '7':
      Basement();
      CleanChannel();
      break;
  }
  //Serial.println(inByte);
  delay(500);
}
void Blink() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(6, LOW);
    delay (random(10, 150));
    digitalWrite(6, HIGH);
    delay (random(10, 150));
  }
}
void DVDplay() {
  irsend.sendNEC(0x926D00FF, 32);
  delay(30000);
  irsend.sendNEC(0x926D2AD5, 32);
  delay(15000);
  irsend.sendNEC(0x926D00FF, 32);
}

void CleanChannel() {
  int inByte = 0;
  Serial.flush();
}

void MainDoor() {
  digitalWrite(8, LOW);//вкл
  delay(1000);
  digitalWrite(8, HIGH);
}

void BathLock() {
  digitalWrite(10, LOW);//вкл
  delay(1000);
  digitalWrite(10, HIGH);
}
void RedLamp() {
  digitalWrite(7, LOW);//вкл
}

void Basement() {
  digitalWrite(9, LOW); //вкл
}
void Reset() {
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}
