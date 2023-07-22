const int AIA = 3;
const int AIB = 4;
const int BIA = 5;
const int BIB = 6;
int RND;
int SensorPin = 2;
byte SPD = 255;
byte rSPD = 100;
int dtime = 1000;
int wtime = 2000;


void setup() {
  Serial.begin(9600);
  pinMode(SensorPin, INPUT);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
}

void loop() {
  sensCheck();
  RND = random(4);
  Serial.println(RND);
  switch (RND) {
    case 0: forward(); break;
    case 1: Wait(); break;
    case 2: Lturn(); break;
    case 3: Rturn(); break;
  }


}

void forward() {
  sensCheck();
  Serial.println("FORWARD");
  analogWrite(AIA, 0);
  analogWrite(AIB, SPD);
  analogWrite(BIA, 0);
  analogWrite(BIB, SPD);
  delay(dtime);
  Stop();
}

void backward() {
  Serial.println("BACKWARD");
  analogWrite(AIA, rSPD);
  analogWrite(AIB, 0);
  analogWrite(BIA, rSPD);
  analogWrite(BIB, 0);
  delay(2000);
  Stop();
}

void Lturn() {
  sensCheck();
  Serial.println("LEFT");
  analogWrite(AIA, SPD);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, SPD);
  delay(dtime);
  Stop();
}

void Rturn() {
  sensCheck();
  Serial.println("RIGHT");
  analogWrite(AIA, 0);
  analogWrite(AIB, SPD);
  analogWrite(BIA, SPD);
  analogWrite(BIB, 0);
  delay(dtime);
  Stop();
}

void Wait() {
  sensCheck();
  Serial.println("WAIT");
  delay(wtime);
}

void Stop() {
  Serial.println("RIGHT");
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}

void sensCheck() {
  if (digitalRead(SensorPin) == LOW) {
    Serial.println("SENSOR LOW");
    backward();
    Stop();
  }
}
