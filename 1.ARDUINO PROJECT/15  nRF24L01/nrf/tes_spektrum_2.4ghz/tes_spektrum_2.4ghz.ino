 #include <SPI.h>  
 #include <LiquidCrystal.h>  
 // The LCD is conected to pins 8, 9, 4, 5, 6, 7  
 LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  
 byte minibars[8][8];  
 //credits to Poor Man's Wireless 2.4GHz Scanner  
 // credits to all others  
 // uses an nRF24L01p connected to an Arduino  
 //   
 // Cables are:  
 //   SS    -> 10  
 //   MOSI   -> 11  
 //   MISO   -> 12  
 //   SCK   -> 13  
 //   
 // and CE    -> A1  
 //  
 // created March 2011 by Rolf Henkel  
 //  
 #define CE A1  
 // Array to hold Channel data  
 #define CHANNELS 64  
 int channel[CHANNELS];  
 // nRF24L01P registers we need  
 #define _NRF24_CONFIG   0x00  
 #define _NRF24_EN_AA    0x01  
 #define _NRF24_RF_CH    0x05  
 #define _NRF24_RF_SETUP  0x06  
 #define _NRF24_RPD     0x09  
 //SoftSPI<SOFT_SPI_MISO_PIN, SOFT_SPI_MOSI_PIN, SOFT_SPI_SCK_PIN, SPI_MODE> spi;  
 // get the value of a nRF24L01p register  
 byte getRegister(byte r)  
 {  
  byte c;  
  PORTB &=~_BV(2); //D10  
  //PORTC &=~_BV(1); //analogue 1 as SS  
  c = SPI.transfer(r&0x1F);  
  c = SPI.transfer(0);   
  PORTB |= _BV(2);  
  //PORTC |= _BV(1); //analogue 1 as SS  
  return(c);  
 }  
 // set the value of a nRF24L01p register  
 void setRegister(byte r, byte v)  
 {  
  PORTB &=~_BV(2);  
  //PORTC &=~_BV(1);  
  SPI.transfer((r&0x1F)|0x20);  
  SPI.transfer(v);  
  PORTB |= _BV(2);  
  //PORTC |= _BV(1);  
 }  
 // power up the nRF24L01p chip  
 void powerUp(void)  
 {  
  setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)|0x02);  
  delayMicroseconds(130);  
 }  
 // switch nRF24L01p off  
 void powerDown(void)  
 {  
  setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)&~0x02);  
 }  
 // enable RX   
 void enable(void)  
 {  
   PORTC |= _BV(1);  
 }  
 // disable RX  
 void disable(void)  
 {  
   PORTC &=~_BV(1);  
 }  
 // setup RX-Mode of nRF24L01p  
 void setRX(void)  
 {  
  setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)|0x01);  
  enable();  
  // this is slightly shorter than  
  // the recommended delay of 130 usec  
  // - but it works for me and speeds things up a little...  
  delayMicroseconds(100);  
 }  
 // scanning all channels in the 2.4GHz band  
 void scanChannels(void)  
 {  
  disable();  
  for( int j=0 ; j<100 ; j++)  
  {  
   for( int i=0 ; i<CHANNELS ; i++)  
   {  
    // select a new channel  
    setRegister(_NRF24_RF_CH,(128*i)/CHANNELS);  
    // switch on RX  
    setRX();  
    // wait enough for RX-things to settle  
    delayMicroseconds(40);  
    // this is actually the point where the RPD-flag  
    // is set, when CE goes low  
    disable();  
    // read out RPD flag; set to 1 if   
    // received power > -64dBm  
    if( getRegister(_NRF24_RPD)>0 )  channel[i]++;  
   }  
  }  
 }  
 void outputChannels(void)  
 {  
  int norm = 0;  
  for( int i=0 ; i<CHANNELS ; i++)  
   if( channel[i]>norm ) norm = channel[i];  
  for( int i=0 ; i<CHANNELS ; i++)  
  {  
   int pos;  
   if( norm!=0 ) pos = (channel[i]*10)/norm;  
   else     pos = 0;  
   if( pos==0 && channel[i]>0 ) pos++;  
   if( pos>8 ) pos = 8;  
   plot_minibars(i/4, pos*2);  
   channel[i] = 0;  
  }  
 }  
 void setup()  
 {  
   // Built the characters for bars.  
  for (int j=0; j<=7; j++)   
  {  
   for (int i=0; i<=7; i++)  
   {  
    if (i<=j)  
    { minibars[j][7-i] = B01110;}    
    else  
    { minibars[j][7-i] = 0;}  
   }  
  }   
  for (int i=0; i<=7;i++)  
  {  
   lcd.createChar(i, minibars[i]);  
  }  
  lcd.begin(16, 2);     
  for (int j=0; j<=7;j++)  
  {  
   lcd.setCursor(j, 0);  
   lcd.write(j);  
   lcd.setCursor(j, 1);  
   lcd.write(7);   
  }  
  // Setup SPI  
  SPI.begin();  
  SPI.setDataMode(SPI_MODE0);  
  SPI.setClockDivider(SPI_CLOCK_DIV2);  
  SPI.setBitOrder(MSBFIRST);  
  // Activate Chip Enable  
  pinMode(CE,OUTPUT);  
  disable();  
  // now start receiver  
  powerUp();  
  // switch off Shockburst  
  setRegister(_NRF24_EN_AA,0x0);  
  // make sure RF-section is set properly   
  // - just write default value...   
  setRegister(_NRF24_RF_SETUP,0x0F);   
  }  
 void loop()   
 {   
  scanChannels();   
  outputChannels();   
 }  
 void plot_minibars(int location, int strngth)  
 {  
  if (strngth>7)  
  {  
   lcd.setCursor(location, 1);  
   lcd.write(7);  
   lcd.setCursor(location, 0);  
   lcd.write(strngth-8);    
  }  
  else  
  {  
   lcd.setCursor(location, 1);  
   lcd.write(strngth);  
   lcd.setCursor(location, 0);  
   lcd.write(32);    
  }  
 } 
