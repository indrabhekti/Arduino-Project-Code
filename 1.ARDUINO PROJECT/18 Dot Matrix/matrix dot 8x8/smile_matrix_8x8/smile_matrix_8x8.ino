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

    byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
    byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
    byte frown[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};

    byte tes[8] = {B01100000,B00100000,B00110000,B00010000,B00011000,B00001000,B00001100,B00000100};
    

 printByte(tes);
     
    delay(2000);


    
    printByte(smile);
     
    delay(2000);

    printByte(neutral);
    
    delay(2000);

    printByte(frown);    

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
