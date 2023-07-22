#define r1 10
#define g1 9
#define b1 11
#define delTime 1000
#define forTime 20

void setup() {
  pinMode(r1,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(b1,OUTPUT);
  digitalWrite(r1,0);
  digitalWrite(g1,0);
  digitalWrite(b1,0);

  //TestBlink();
  SmoothGlow();
  ColorMix();
}

void loop(){
  ColorMix();
}

void TestBlink(){
  digitalWrite(r1,1);
  delay(delTime);
  digitalWrite(r1,0);
  delay(delTime);
  digitalWrite(g1,1);
  delay(delTime);
  digitalWrite(g1,0);
  delay(delTime);
  digitalWrite(b1,1);
  delay(delTime);
  digitalWrite(b1,0);
  delay(delTime);
}

void SmoothGlow(){
  for (int i=0;i<255;i++){
    analogWrite(r1,i);
    delay(forTime);
    }
  for (int i=255;i>0;i--){
    analogWrite(r1,i);
    delay(forTime);
    }
  digitalWrite(r1,0);
  delay(delTime);
  for (int i=0;i<255;i++){
    analogWrite(g1,i);
    delay(forTime);
    }
  for (int i=255;i>0;i--){
    analogWrite(g1,i);
    delay(forTime);
    }
  digitalWrite(g1,0);
  delay(delTime);
  for (int i=0;i<255;i++){
    analogWrite(b1,i);
    delay(forTime);
    }
  for (int i=255;i>0;i--){
    analogWrite(b1,i);
    delay(forTime);
    }
  digitalWrite(b1,0);
  delay(delTime);
  }

void ColorMix(){
  //orange
  analogWrite(r1,255);
  analogWrite(g1,128);
  analogWrite(b1,0);
  delay(delTime);

  //aqua
  analogWrite(r1,0);
  analogWrite(g1,255);
  analogWrite(b1,255);
  delay(delTime);

  //purple
  analogWrite(r1,255);
  analogWrite(g1,0);
  analogWrite(b1,255);
  delay(delTime);

  //yellow
  analogWrite(r1,255);
  analogWrite(g1,255);
  analogWrite(b1,0);
  delay(delTime);

  //lime
  analogWrite(r1,128);
  analogWrite(g1,255);
  analogWrite(b1,0);
  delay(delTime);
  }
