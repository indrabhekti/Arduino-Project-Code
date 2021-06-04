//Arduino Base Converter with 4x4 Keypad and I2C LCD 20X4
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27
//for a 20 chars and 4 line display

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
byte mask = 1;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print characters on LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  //lcd.print("I2C Serial LCD ");
  Serial.begin(9600);
}

void loop()
{

  lcd.setCursor(0,0);
  char key = keypad.getKey();

  if (key != NO_KEY)
  {

    if(key == '0')
    key = 0x00;
    if(key == '1')
    key = 0x01;
    if(key == '2')
    key = 0x02;
    if(key == '3')
    key = 0x03;
    if(key == '4')
    key = 0x04;
    if(key == '5')
    key = 0x05;
    if(key == '6')
    key = 0x06;
    if(key == '7')
    key = 0x07;
    if(key == '8')
    key = 0x08;
    if(key == '9')
    key = 0x09;
    if(key == 'A')
    key = 0x0A;
    if(key == 'B')
    key = 0x0B;
    if(key == 'C')
    key = 0x0C;
    if(key == 'D')
    key = 0x0D;
    if(key == '#')
    key = 0x0E;
    if(key == '*')
    key = 0x0F;
    //-------------------------------------------------------------------
  for ( uint8_t bitMask = 128; bitMask != 0; bitMask = bitMask >> 1 ) 
  {
  if ( key & bitMask ) 
    {
    //Serial.print('1');
    lcd.print("1");
   } 
    else 
   {
    //Serial.print('0');
    lcd.print("0");
   }
  }

    //-------------------------------------------------------------------
  }
}
