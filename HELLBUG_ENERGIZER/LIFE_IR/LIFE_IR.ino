#include <IRremote.h>
int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int AIA = 3;
const int AIB = 4;
const int BIA = 8;
const int BIB = 9;
int IRdata = 0;
byte SPD = 255;
byte lrSPD = 150;
int dtime = 200;

void setup() {
  Serial.begin(9600);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {
 if (irrecv.decode(&results)) {
    IRdata = results.value;
    switch (IRdata) {
      case 16736925: forward(); break;
      case 16754775: backward(); break;
      case 16761405: Lturn(); break;
      case 16720605: Rturn(); break;
      case 16712445: Stop(); break;
      case -1: RepeatCheck(); break;
    }
    irrecv.resume();
    }
    //else delay(100); Stop(); 
}

void forward() {
  Serial.println("FORWARD");
  analogWrite(AIA, 0);
  analogWrite(AIB, SPD);
  analogWrite(BIA, 0);
  analogWrite(BIB, SPD);
  }

void backward() {
  Serial.println("BACKWARD");
  analogWrite(AIA, SPD);
  analogWrite(AIB, 0);
  analogWrite(BIA, SPD);
  analogWrite(BIB, 0);
  //delay(1000);
  //Stop();
}

void Lturn() {
  Serial.println("RIGHT");
  analogWrite(AIA, SPD);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, SPD);
  //RepeatCheck();
  delay(dtime);
  Stop();
}

void Rturn() {
  Serial.println("LEFT");
  analogWrite(AIA, 0);
  analogWrite(AIB, SPD);
  analogWrite(BIA, SPD);
  analogWrite(BIB, 0);
  //RepeatCheck();
  delay(dtime);
  Stop();
}

void Stop() {
  Serial.println("STOP");
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}

void RepeatCheck(){
  Serial.println("repeat");
      }
