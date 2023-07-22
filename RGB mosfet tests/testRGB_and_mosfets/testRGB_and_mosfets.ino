#define r1 9
#define g1 10
#define b1 11
#define delTime 500

void setup() {
  pinMode(r1,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(b1,OUTPUT);

}

void loop() {
  analogWrite(r1,255);
  delay(delTime);
  analogWrite(b1,255);
  delay(delTime);
  analogWrite(g1,255);
  delay(delTime);
  analogWrite(r1,0);
  delay(delTime);
  analogWrite(b1,0);
  delay(delTime);
  analogWrite(g1,0);
  delay(delTime);
}
