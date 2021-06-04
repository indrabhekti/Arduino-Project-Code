#include <DS3231.h>
#include <Wire.h> // Library untuk komunikasi I2C (harus install library)
#include <LiquidCrystal_I2C.h> // Library  LCD(harus intall library)ry 
DS3231  rtc(SDA, SCL);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() { 
 rtc.begin(); // Initialize the rtc object
 lcd.init();
  lcd.backlight();

}
void loop() { 
 lcd.setCursor(0,0);
 lcd.print("JAM:  ");
 lcd.print(rtc.getTimeStr());
 
 lcd.setCursor(0,1);
 lcd.print("TGL: ");
 lcd.print(rtc.getDateStr());
 
 delay(1000); 
}
