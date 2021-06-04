#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;



LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display

   
   
}


void loop(){ 

   byte hurufi[8] = {B00111100,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000,B00111100};
  byte love[8] = {B00000000,B01100110,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};
   byte hurufu[8] = {B00000000,B11000011,B11000011,B11000011,B11000011,B11000011,B11111111,B11111111};
    

 printByte(hurufi);
     
    delay(2000);


    
    printByte(love);
     
    delay(2000);

    printByte(hurufu);
    
    delay(2000);

   
 
   
    lc.clearDisplay(0);
    
    delay(1000);
}



void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
