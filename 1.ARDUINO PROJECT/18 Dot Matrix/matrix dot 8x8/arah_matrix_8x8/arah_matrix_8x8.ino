#include <LedControl.h>

int DIN = 12;
int CS =  10;
int CLK = 11;



LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display

   
   
}


void loop(){ 

byte atas[] = { B00011000,B00111100,B01111110,B11111111,B11111111,B00011000,B00011000,B00011000};
byte bawah[] = {B00011000,B00011000,B00011000,B11111111,B11111111,B01111110,B00111100,B00011000};
byte kanan[] = {B00011000,B00011100,B00011110,B11111111,B11111111,B00011110,B00011100,B00011000};
byte kiri[] = {B00011000,B00111000,B01111000,B11111111,B11111111,B01111000,B00111000,B00011000};
byte silang[] = {B10000001,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B10000001};
byte center[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};



    printByte(atas);
     
    delay(2000);
    
    printByte(bawah);
     
    delay(2000);

    printByte(kanan);
     
    delay(2000);

    printByte(kiri);
     
    delay(2000);

    printByte(silang);
     
    delay(2000);

    printByte(center);
     
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
