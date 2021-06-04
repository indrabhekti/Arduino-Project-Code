#include <DS3231.h>
#include <LiquidCrystal_I2C.h> 
DS3231 rtc(SDA, SCL);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
rtc.begin();
 lcd.init();
  lcd.backlight();
//  rtc.setDOW(SATURDAY);     // hari
  // rtc.setTime(19, 43, 00);     // jam format 24 
 // rtc.setDate(11, 7, 2020);   // tanggal 11 juli 2020

}

void loop() {
lcd.setCursor(0,0);
lcd.print("HAVE A NICE DAY ");

lcd.setCursor(0,1);
lcd.print("Time:  ");
lcd.print(rtc.getTimeStr());
delay(3000);

lcd.setCursor(0,1);
lcd.print("Date: ");
lcd.print(rtc.getDateStr());
delay(3000);

lcd.setCursor(0,1);
lcd.print("Day:    ");
lcd.print(rtc.getDOWStr());
lcd.print(" ");
delay(3000);

lcd.setCursor(0,1);
lcd.print("Temp:   ");
lcd.print(rtc.getTemp());
lcd.print(" C");
lcd.print(" ");
delay(3000);
}
