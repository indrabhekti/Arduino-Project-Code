#include <Wire.h> // Library untuk komunikasi I2C (harus install library)
#include <LiquidCrystal_I2C.h> // Library  LCD(harus intall library)
// SDA pin di A4 and SCL pin di A5.
// Connect LCD via I2C, default address 0x27 (default addres harus di cari dulu)(A0-A2 tidak di jumper)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // (default addres,panjang kolom lcd,lebar kolom lcd)(0x27,16,2) 0x27 untuk addres ,16x2 LCD.
int count = 0;


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.backlight();
  int temp = 10;
  lcd.clear();

}


void loop() {
  lcd.clear();
  lcd.setCursor(0, 0); //
  lcd.print(       "4bit binary"); // isi kata
  lcd.setCursor(2, 1); //

  lcd.print(          count);
  count++;
  if ( count >= 15) count = 0;
  delay(2000);
}
