
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

   lcd.setCursor(0, 0);
  lcd.print("tes scrooling text");
  
   lcd.setCursor(2,1);
  lcd.print("by dafa wijaya");
  
}

void loop() {

    lcd.scrollDisplayLeft();
    //lcd.scrollDisplayRight();
    delay(500);
    
  }
