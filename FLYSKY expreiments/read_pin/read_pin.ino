int pin1 = 10;
int pin2 = 9;
unsigned long duration1;
unsigned long duration2;

 
void setup()
{
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  Serial.begin(9600);
}
 
void loop()
{
  duration1 = pulseIn(pin1, HIGH);
  duration2 = pulseIn(pin2, HIGH);
  Serial.print(duration1);
  Serial.print("---");
  Serial.println(duration2);
}


