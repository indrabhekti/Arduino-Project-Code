

#include "SPI.h" // SPI library
#include "MFRC522.h" // RFID library (https://github.com/miguelbalboa/rfid)

const int pinRST = 9;
const int pinSDA = 10;

MFRC522 mfrc522(pinSDA, pinRST); // 

void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) { // (true, if RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
    if(mfrc522.PICC_ReadCardSerial()) { // true, if RFID tag/card was read
      Serial.print("RFID TAG ID:");
      for (byte i = 0; i < mfrc522.uid.size; ++i) { // read id (in parts)
        Serial.print(mfrc522.uid.uidByte[i], HEX); // print id as hex values
        Serial.print(" "); // 
        delay (200);
      }
      Serial.println(); // 
    }
  }
}
