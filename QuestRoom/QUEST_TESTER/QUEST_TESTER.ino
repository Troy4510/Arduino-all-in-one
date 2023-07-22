#include <IRremote.h>

IRsend irsend;
int i;
int inByte;
boolean RedStatus = false;        //красная лампа    -пин7   реле7    xp0
boolean BraStatus = false;        //основной свет    -пин6   реле6    xp1
boolean MainDStatus = false;      //входная дверь    -датчикПин2      xp2
boolean BasementStatus = false;   //подвал           -датчикПин4      xp3
boolean BootStatus = false;       //ботинок          -датчикПин5      xp4
boolean MainLock = false;         //замокВхДвери     -пин8  реле8     xp5
boolean ToiletLock = false;       //замокСанузел     -пин10 реле5     xp6
boolean RstStatus = false;        //Сброс?           -датчикПин13     xp7
int ExchangePocket[8] = {0, 0, 0, 0, 0, 0, 0, 0};
void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    inByte = Serial.read();
  }
  else inByte = 255;

  switch (inByte) {

    case 1:
      DVDplay();
      CleanChannel();
      break;

    case 2:
      Blink();
      CleanChannel();
      break;


  }
  Serial.println(inByte);
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

void RedLamp();

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

void TransmitPocket() {
  CleanChannel();

  if (RedStatus == true)        {
    ExchangePocket[0] = 1;
  } else {
    ExchangePocket[0] = 0;
  }
  if (BraStatus == true)        {
    ExchangePocket[1] = 1;
  } else {
    ExchangePocket[1] = 0;
  }
  if (MainDStatus == true)      {
    ExchangePocket[2] = 1;
  } else {
    ExchangePocket[2] = 0;
  }
  if (BasementStatus == true)   {
    ExchangePocket[3] = 1;
  } else {
    ExchangePocket[3] = 0;
  }
  if (BootStatus == true)       {
    ExchangePocket[4] = 1;
  } else {
    ExchangePocket[4] = 0;
  }
  if (MainLock == true)         {
    ExchangePocket[5] = 1;
  } else {
    ExchangePocket[5] = 0;
  }
  if (ToiletLock == true)       {
    ExchangePocket[6] = 1;
  } else {
    ExchangePocket[6] = 0;
  }
  if (RstStatus == true)        {
    ExchangePocket[7] = 1;
  } else {
    ExchangePocket[7] = 0;
  }
  //delay(100);
  for (int i = 0; i < 9; i++) {
    Serial.write(ExchangePocket[i]);
  }
}

void ResievePocket() {
  for (int i = 0; i < 9; i++) {
    ExchangePocket[i] = Serial.read();
  }
  if (ExchangePocket[0] == 1)    {
    RedStatus = true;
  } else {
    RedStatus = false;
  }
  if (ExchangePocket[1] == 1)    {
    BraStatus = true;
  } else {
    BraStatus = false;
  }
  if (ExchangePocket[2] == 1)    {
    MainDStatus = true;
  } else {
    MainDStatus = false;
  }
  if (ExchangePocket[3] == 1)    {
    BasementStatus = true;
  } else {
    BasementStatus = false;
  }
  if (ExchangePocket[4] == 1)    {
    BootStatus = true;
  } else {
    BootStatus = false;
  }
  if (ExchangePocket[5] == 1)    {
    MainLock = true;
  } else {
    MainLock = false;
  }
  if (ExchangePocket[6] == 1)    {
    ToiletLock = true;
  } else {
    ToiletLock = false;
  }
  if (ExchangePocket[7] == 1)    {
    RstStatus = true;
  } else {
    RstStatus = false;
  }
  CleanChannel();
}
