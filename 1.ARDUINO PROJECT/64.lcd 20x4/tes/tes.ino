#include <Wire.h>
#include <LiquidCrystal_I2C.h>


//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7
LiquidCrystal_I2C lcd(0x27,20,4); // 0x27 is the default I2C bus address of the backpack-see article
void setup()
{

   lcd.init (); 
   lcd.backlight ();
   lcd.print("Hello, World!");
   lcd.setCursor(0,1);
   lcd.print("Good Day");   
}
void loop()
{
}
