#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

/**        
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(12,13);    // 2:RX 3:TX, you can choose your favourite pins.

//uint8_t records[7]; // save record
uint8_t buf[32];
#define zeroRecord  (0)
#define oneRecord  (1)
#define twoRecord  (2)
#define threeRecord  (3)
#define fourRecord  (4)

/**
  @brief   Print signature, if the character is invisible, 
           print hexible value instead.
  @param   buf     --> command length
           len     --> number of parameters
*/
/**
  @brief   Print signature, if the character is invisible, 
           print hexible value instead.
  @param   buf  -->  VR module return value when voice is recognized.
             buf[0]  -->  Group mode(FF: None Group, 0x8n: User, 0x0n:System
             buf[1]  -->  number of record which is recognized. 
             buf[2]  -->  Recognizer index(position) value of the recognized record.
             buf[3]  -->  Signature length
             buf[4]~buf[n] --> Signature
*/

void setup()
{
  /** initialize */
  myVR.begin(9600);
  Serial.begin(115200);
  myVR.load((uint8_t)zeroRecord);
  myVR.load((uint8_t)oneRecord);
  myVR.load((uint8_t)twoRecord);
  myVR.load((uint8_t)threeRecord);
  myVR.load((uint8_t)fourRecord);
}   
void loop()
{
  int ret;
  ret = myVR.recognize(buf,5);// скорее всего буфер(32байта), 5первых байт скачать
  if(ret>0){
    Serial.println("somedata ret");
    Serial.println(buf[2], HEX);
    Serial.print(char (buf[4]));
    Serial.print(char (buf[5]));
    Serial.print(char (buf[6]));
    Serial.print(char (buf[7]));
    Serial.println(char (buf[8]));
    }
   
  }




