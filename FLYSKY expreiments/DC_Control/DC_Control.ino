int Ch1 = 9;         //1000-2000
//int Ch2 = 3;          //1000-2000
int DC1_PWM = 10;     //0-255
//int DC2_PWM = 11;     //0-255
//int DC1_Dir = 0;
//int DC2_Dir = 0;
int spd = 0;

unsigned long ChData1;
unsigned long ChData2;

 
void setup()
{
  pinMode(Ch1, INPUT);
  //pinMode(Ch2, INPUT);
  pinMode(DC1_PWM, OUTPUT); //e1
  //pinMode(DC2_PWM, OUTPUT);
  pinMode(7, OUTPUT);      //in1
  pinMode(8, OUTPUT);      //in2

  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  Serial.begin(9600);
}


 
void loop()
{
  //MotorsTest();
  RCmotor();
}



void Diagnostics()
{
  //ChData1 = pulseIn(Ch1, HIGH);
  //ChData2 = pulseIn(Ch2, HIGH);
  //Serial.print(ChData1);
  Serial.print("---");
  //Serial.println(ChData2);
}


void MotorsTest()
{
  //direction = move front
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
  //change speed
  analogWrite(DC1_PWM, 100);
  delay (2000);
  analogWrite(DC1_PWM, 150);
  delay (2000);
  analogWrite(DC1_PWM, 170);
  delay (2000);
  analogWrite(DC1_PWM, 200);
  delay (2000);
  analogWrite(DC1_PWM, 255);
  delay (2000);
  analogWrite(DC1_PWM, 0);
  delay (2000);

  //soft stop
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void RCmotor()
{
  ChData1 = pulseIn(Ch1, HIGH);
  Serial.print(ChData1);
  spd = map(ChData1, 1000, 2000, 70, 255);
  Serial.print("---");
  analogWrite(DC1_PWM, spd);
  Serial.println(spd);
  delay(100);
}

