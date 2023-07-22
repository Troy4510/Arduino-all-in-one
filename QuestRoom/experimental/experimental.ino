#include <UTFT.h>
extern uint8_t SmallFont[];
UTFT myGLCD(NIC35WS,38,39,40,41);

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop()
{
myGLCD.clrScr();
for (int i=1; i<(200); i++){
  myGLCD.setColor(12,211,1);
  myGLCD.fillCircle(i,i,10);
  myGLCD.setColor(0,0,0);
  myGLCD.drawCircle(i,i,11);
  myGLCD.drawCircle(i,i,12);
  myGLCD.drawCircle(i,i,13);
  delay(10);
}
}
