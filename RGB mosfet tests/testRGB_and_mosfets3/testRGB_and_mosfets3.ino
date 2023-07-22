#define r1 10
#define g1 9
#define b1 11
#define delTime 1000

void setup() {
  pinMode(r1,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(b1,OUTPUT);
  digitalWrite(r1,0);
  digitalWrite(g1,0);
  digitalWrite(b1,0);
  delay(5000);

  TestBlink();
}

void loop(){
  
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
  }
