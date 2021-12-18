/*RFID tag scan code
 * https://srituhobby.com
 */
 
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN  10
byte readCard[4];
byte a = 0;
Servo myservo;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  myservo.attach(3);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return 0;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }

  a = 0;
  Serial.println(F("Scanned PICC's UID:"));

  String CardID ="";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    CardID += mfrc522.uid.uidByte[i];
  }
  Serial.print(CardID);
  Serial.println();
  if(CardID == "1641212740"){
      Serial.println("Correct Card");
      int i = 0;
      for(i=0;i<90;i++){
              myservo.write (i); 
              delay (100);
        }
      delay(1000);
      for(i=90;i>0;i--){
              myservo.write (i); 
              delay (100);
        }
    }
  mfrc522.PICC_HaltA();
  return 1;
}
