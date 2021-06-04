#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
  
// make some custom characters:
byte Heart[8] = {
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};


void setup() 
{
  // initialize LCD and set up the number of columns and rows: 
   lcd.init();
  lcd.backlight();  

  // create a new character
  lcd.createChar(0, Heart);
  // create a new character
  lcd.createChar(1, Heart);
  // create a new character
  lcd.createChar(2, Heart);
  // create a new character
  lcd.createChar(3, Heart);
  // create a new character
  lcd.createChar(4, Heart);
  // create a new character
  lcd.createChar(5, Heart);
  // create a new character
  lcd.createChar(6, Heart);
  // create a new character
  lcd.createChar(7, Heart);

  // Clears the LCD screen
  lcd.clear();

  // Print a message to the lcd.
  lcd.print("     love u");
}

// Print All the custom characters
void loop() 
{ 
  lcd.setCursor(0, 1);
  lcd.write(byte(0));  // menamilkan lcd.createChar(0, Heart);

  lcd.setCursor(2, 1);
  lcd.write(byte(1));

  lcd.setCursor(4, 1);
  lcd.write(byte(2));

  lcd.setCursor(6, 1);
  lcd.write(byte(3));

  lcd.setCursor(8, 1);
  lcd.write(byte(4));

  lcd.setCursor(10, 1);
  lcd.write(byte(5));

  lcd.setCursor(12, 1);
  lcd.write(byte(6));

  lcd.setCursor(14, 1);
  lcd.write(byte(7));
}
