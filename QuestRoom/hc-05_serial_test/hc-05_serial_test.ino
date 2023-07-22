byte somedata = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
somedata = Serial.read();
Serial.println(somedata);
somedata = 0;
Serial.write(0);
delay(3000);
}
