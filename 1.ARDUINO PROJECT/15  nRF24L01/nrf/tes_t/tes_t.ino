/*
 Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...
 You can: copy it, use it, modify it, share it or just plain ignore it!
 Thx!

*/

// NRF24L01 Module Tutorial - Code for Transmitter using Arduino NANO

//Include needed Libraries at beginning
#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"
#include <Wire.h> 

#include <LiquidCrystal.h> // set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define SwitchPin 8 // Arcade switch is connected to Pin 8 on NANO
int SentMessage[1] = {000}; // Used to store value before being sent through the NRF24L01

RF24 radio(9, 10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO
const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01

void setup(void) {

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
 lcd.setCursor(0, 0);
 lcd.print("Initializinglcd");
 lcd.setCursor(0, 1);
 lcd.print("Transmitter");
 delay(2000);

 radio.begin(); // Start the NRF24L01
 
 // Max power
 radio.setPALevel( RF24_PA_MAX ) ;

 // Min speed (for better range I presume)
 radio.setDataRate( RF24_250KBPS ) ;

 // 8 bits CRC
 radio.setCRCLength( RF24_CRC_8 ) ;

 // increase the delay between retries & # of retries
 radio.setRetries(15, 15);
 radio.setAutoAck(false);
 radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
}

void loop(void) {

 int num ;
 num = random(0, 100);
 SentMessage[0] = num;
 outputToLCD("Sending data:", (String) SentMessage[0], 0);
 radio.write(SentMessage, 1); // Send value through NRF24L01
 delay(500);

}

void outputToLCD(String message1, String message2, int delayValue) {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print(message1);
 lcd.setCursor(0, 1);
 lcd.print(message2);
 delay(delayValue);
}
