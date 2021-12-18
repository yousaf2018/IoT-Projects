/* Read RFID Tag with RC522 RFID Reader
 *  Made by miliohm.com
 */
 
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h> // including servo library.
constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
Servo servo_1; // Giving name to servo.
#define red_led D0
#define green_led D2
#define servo D1
String tag;
void setup() {
  Serial.begin(115200);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(servo         ,OUTPUT);
  servo_1.attach(D1 ); // Attaching Servo to D1
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(servo, LOW);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
}
void loop() {
  
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    // || tag == "60588474"
    if(tag == "1641212740"){
        Serial.println("Access granted");
        digitalWrite(green_led,HIGH);
        digitalWrite(servo,HIGH);
      }
    else{
        Serial.println("Access denied");
        digitalWrite(red_led,HIGH);
        digitalWrite(green_led,LOW);
        digitalWrite(servo,LOW);
      }
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
