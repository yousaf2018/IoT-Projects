// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLtY8I3990"
#define BLYNK_DEVICE_NAME "Smart Home"
#include <Servo.h> // including servo library.

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD
Servo servo_1; // Giving name to servo.
#include "BlynkEdgent.h"
BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); // parameter as int 
  if(s0 == HIGH)
  {    
    digitalWrite(D2,HIGH);
    delay(10);
    }  
    if(s0 == LOW)
  {
    digitalWrite(D2,LOW);
    delay(10);
    }  
}
BLYNK_WRITE(V1)
{
  int s0 = param.asInt(); // parameter as int 
  if(s0 == HIGH)
  {    
      int i = 0;
      for(i=0;i<90;i++){
              servo_1.write (i); 
              delay (100);
        }

    }  
    if(s0 == LOW)
  {
      int i = 90;
      for(i=90;i>0;i--){
              servo_1.write (i); 
              delay (100);
        }

    }
}  
void setup()
{
  Serial.begin(9600);
  servo_1.attach(0); // Attaching Servo to D3
  pinMode(D2,OUTPUT);
  digitalWrite(D2,LOW);
  BlynkEdgent.begin();
}

void loop() {

    BlynkEdgent.run();
}
