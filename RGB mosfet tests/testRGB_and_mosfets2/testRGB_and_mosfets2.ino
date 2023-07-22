#define r1 10
#define g1 9
#define b1 11
#define delTime 1000

void setup() {
  pinMode(r1,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(b1,OUTPUT);
  analogWrite(r1,0);
  analogWrite(g1,0);
  analogWrite(b1,0);
  delay(5000);

}

void loop() {
  analogWrite(r1,255);
  delay(delTime);
  analogWrite(r1,0);
  delay(delTime);
  analogWrite(g1,255);
  delay(delTime);
  analogWrite(g1,0);
  delay(delTime);
  analogWrite(b1,255);
  delay(delTime);
  analogWrite(b1,0);
  delay(delTime);
}
