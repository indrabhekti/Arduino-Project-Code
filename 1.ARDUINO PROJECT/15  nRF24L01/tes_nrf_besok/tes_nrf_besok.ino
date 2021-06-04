
/* A simple 2.4GHZ spectrum analyser with nrf24l01,character lcd and an arduino

   http://blog.riyas.org/2014/06/a-simple-24ghz-spectrum-analyser-arduino-lcd-shield.html

   Connect the nrf module to the spi pins (10,11,12,13)  and A1 (for CE) and an lcd to pin 8,9,4,5,6,7
*/

/*
    exact wifi channells map to 16 bars: (0), 1...13, (hole), 14
*/

#include <SPI.h>

#include <Wire.h> // Library untuk komunikasi I2C (harus install library)
#include <LiquidCrystal_I2C.h>
// The LCD is conected to pins RS-8, EN-9, D4-4, D5-5, D6-6, D7-7, RW-GND, VO-GND
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
byte minibars[8][8];
//credits to Poor Man's Wireless 2.4GHz Scanner
// credits to all others
// uses an nRF24L01p connected to an Arduino
//
// Cables are:
//   CS    -> 10
//   MOSI   -> 11
//   MISO   -> 12
//   SCK   -> 13
// and CE    -> A1
//
// Modified from original code: March 2011 by Rolf Henkel
//
#define CE A1
// Array to hold Channel data
#define CHANNELS 94
int channel[CHANNELS];
// nRF24L01P registers we need
#define _NRF24_CONFIG   0x00
#define _NRF24_EN_AA    0x01
#define _NRF24_RF_CH    0x05
#define _NRF24_RF_SETUP  0x06
#define _NRF24_RPD     0x09
//SoftSPI<SOFT_SPI_MISO_PIN, SOFT_SPI_MOSI_PIN, SOFT_SPI_SCK_PIN, SPI_MODE> spi;

byte CH_LEVEL[16];

byte scan_time = 255;  // minimum 130 for system + 40 for AGC - sensitivity to packet density (cca 250us per packet)

byte SW_MODE = 1; // 0 = live wifi scanner   1 = spectrum occupy
byte SCAN_COUNT = 32; // No of scans per one display - sensitivity to density
// SCAN_COUNT * 5 (MHz in ordinary channel) <256
byte DISP_ZOOM = 1;  // ZOOM level 0=1, 1=2, 2=4, 3=8, 4=16, 5=32 ...
// full "strength" to 15 levels, but some saturation wanted

void LCDdemo() {  // Built the characters for bars.
  for (byte j = 0; j <= 7; j++)
  {
    for (byte i = 0; i <= 7; i++)
    {
      if (i <= j)
      {
        minibars[j][7 - i] = B01110;
      }
      else
      {
        minibars[j][7 - i] = 0;
      }
    }
  }
  for (byte i = 0; i <= 7; i++)
  {
    lcd.createChar(i, minibars[i]);
  }
  lcd.init();
  lcd.backlight();
  for (byte j = 0; j <= 7; j++)
  {
    lcd.setCursor(j, 0);
    lcd.write(j);
    lcd.setCursor(j, 1);
    lcd.write(7);
  }
}


byte getRegister(byte r)   // get the value of a nRF24L01p register
{
  byte c;
  PORTB &= ~_BV(2); //D10
  //PORTC &=~_BV(1); //analogue 1 as SS
  c = SPI.transfer(r & 0x1F);
  c = SPI.transfer(0);
  PORTB |= _BV(2);
  //PORTC |= _BV(1); //analogue 1 as SS
  return (c);
}


void setRegister(byte r, byte v)   // set the value of a nRF24L01p register
{
  PORTB &= ~_BV(2);
  //PORTC &=~_BV(1);
  SPI.transfer((r & 0x1F) | 0x20);
  SPI.transfer(v);
  PORTB |= _BV(2);
  //PORTC |= _BV(1);
}


void powerUp(void)  // power up the nRF24L01p chip
{ setRegister(_NRF24_CONFIG, getRegister(_NRF24_CONFIG) | 0x02);
  delayMicroseconds(130);
}

void powerDown(void) {
  setRegister(_NRF24_CONFIG, getRegister(_NRF24_CONFIG) & ~0x02);  // switch nRF24L01p off
}
void enable(void) {
  PORTC |= _BV(1); // enable RX
}
void disable(void) {
  PORTC &= ~_BV(1); // disable RX
}

void setRX(void)   // setup RX-Mode of nRF24L01p
{ setRegister(_NRF24_CONFIG, getRegister(_NRF24_CONFIG) | 0x01);
  enable();
  delayMicroseconds(scan_time);    // the recommended delay of 130 usec
}


void scanChannels(void)   // scanning all channels in the 2.4GHz band
{ disable();
  for ( byte j = 0 ; j <= SCAN_COUNT ; j++)
  { for ( byte i = 0 ; i < CHANNELS ; i++)
    {
      setRegister(_NRF24_RF_CH, i); // select a new channel
      setRX();  // switch on RX
      disable();        // this is actually the point where the RPD-flag   is set, when CE goes low
      if ( getRegister(_NRF24_RPD) > 0 )  channel[i]++; // read out RPD flag; set to 1 if  received power > -64dBm
    }
  }
}

/*      https://upload.wikimedia.org/wikipedia/commons/thumb/8/84/NonOverlappingChannels2.4GHzWLAN-en.svg/720px-NonOverlappingChannels2.4GHzWLAN-en.svg.png
  WIFI MHz  NRF-CH  od-do
  -   2401     1    1-8
  1   2412    12    9-14
  2   2417    17    15-19
  3   2422    22    20-24
  4   2427    27    25-29
  5   2432    32    30-34
  6   2437    37    35-39
  7   2442    42    40-44
  8   2447    47    45-49
  9   2452    52    50-54
  10  2457    57    55-59
  11  2462    62    60-64
  12  2467    67    65-69
  13  2472    72    70-74
  --  2477    77    75-79
  14  2484    84    80-94

  802.11b - 20MHz (22MHz), ch. 1,6,11,14 - end 2.494 GHz
        g/n       16,25MHz (20MHz)   1,5,9,13 - end 2.4835 GHz
        n         33,75MHz (40MHz)    3,11  - end 2.4835 GHz
*/

void outputChannels(void)
{
  feedChannel(0, 1, 8);
  feedChannel(1, 9, 14);
  feedChannel(2, 15, 19);
  feedChannel(3, 20, 24);
  feedChannel(4, 25, 29);
  feedChannel(5, 30, 34);
  feedChannel(6, 35, 39);
  feedChannel(7, 40, 44);
  feedChannel(8, 45, 49);
  feedChannel(9, 50, 54);
  feedChannel(10, 55, 59);
  feedChannel(11, 60, 64);
  feedChannel(12, 65, 69);
  feedChannel(13, 70, 74);
  feedChannel(14, 75, 79);
  feedChannel(15, 80, 94);
}

void feedChannel(byte CH_wifi, byte CH_low, byte CH_high)
{
  byte strength = 0;
  for ( byte i = CH_low ; i <= CH_high ; i++) {
    strength = strength + channel[i];
    if (CH_LEVEL[CH_wifi] < strength) CH_LEVEL[CH_wifi] = strength;
    if (SW_MODE == 0) {
      plot_minibars(CH_wifi, strength);
    }
    else              {
      plot_minibars(CH_wifi, CH_LEVEL[CH_wifi]);
    }
    channel[i] = 0;
  }
}


void plot_minibars(byte location, byte strngth)
{
  byte str_disp = strngth >> DISP_ZOOM; //ZOOM
  if (str_disp > 15)
  {
    lcd.setCursor(location, 1);
    lcd.write(7);
    lcd.setCursor(location, 0);
    lcd.write(7);
  }
  else if (str_disp > 7)
  {
    lcd.setCursor(location, 1);
    lcd.write(7);
    lcd.setCursor(location, 0);
    lcd.write(str_disp - 8);
  }
  else
  {
    lcd.setCursor(location, 1);
    lcd.write(str_disp);
    lcd.setCursor(location, 0);
    lcd.write(32);
  }
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  LCDdemo();

  // Setup SPI
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.setBitOrder(MSBFIRST);

  pinMode(CE, OUTPUT);   // Activate Chip Enable
  disable();
  powerUp();    // now start receiver
  setRegister(_NRF24_EN_AA, 0x0);   // switch off Shockburst
  // make sure RF-section is set properly
  // - just write default value...
  setRegister(_NRF24_RF_SETUP, 0x0F);
}

void loop()
{
  scanChannels();
  outputChannels();
}
