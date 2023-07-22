const int AIA = 3;
const int AIB = 4;
const int BIA = 5;
const int BIB = 6;
byte rSPD = 200;

void setup() {
  analogWrite(AIA, rSPD);
  analogWrite(AIB, 0);
  analogWrite(BIA, rSPD);
  analogWrite(BIB, 0);
  delay(2000);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}

void loop() {
 
}
