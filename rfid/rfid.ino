/*
* Pin layout should be as follows (on Arduino Uno):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS: Pin 10
* RST: Pin 9
*/
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

// Setup variables:
    int serNum0;
    int serNum1;
    int serNum2;
    int serNum3;
    int serNum4;

void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  mfrc522.PCD_Init();  
}

void loop()
{ 
    if (mfrc522.PICC_IsNewCardPresent()) {
        if (mfrc522.PICC_ReadCardSerial()){
                Serial.println(" ");
                Serial.println("Card found");
                Serial.print("Hex: ");
		Serial.print(mfrc522.uid.uidByte[0], DEC);
                Serial.print(", ");
		Serial.print(mfrc522.uid.uidByte[1], DEC);
                Serial.print(", ");
		Serial.print(mfrc522.uid.uidByte[2], DEC);
                Serial.print(", ");
		Serial.print(mfrc522.uid.uidByte[3], DEC);
                Serial.print(", ");
		Serial.print(mfrc522.uid.uidByte[4], DEC);
                Serial.println(" ");      
                    Serial.print(mfrc522.uid.uidByte[5], DEC);
                Serial.println(" ");           
          }
    }
}



