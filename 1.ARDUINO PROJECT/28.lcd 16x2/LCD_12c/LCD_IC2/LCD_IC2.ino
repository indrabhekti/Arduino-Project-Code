
//project arduino lcd 16 x 2 dengan ic2
//dafa wijaya

// vcc 5v ,gnd gnd,scl A5, sda A4


#include <Wire.h> // Library untuk komunikasi I2C (harus install library)
#include <LiquidCrystal_I2C.h> // Library  LCD(harus intall library)
// SDA pin di A4 and SCL pin di A5.
// Connect LCD via I2C, default address 0x27 (default addres harus di cari dulu)(A0-A2 tidak di jumper)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // (default addres,panjang kolom lcd,lebar kolom lcd)(0x27,16,2) 0x27 untuk addres ,16x2 LCD.
void setup() {
  // Initiate LCD:
  lcd.begin();
  lcd.backlight();
}
void loop() {

  lcd.setCursor(0, 0); // 
  lcd.print("hallo"); // isi kata 
  lcd.setCursor(2, 1); //
  lcd.print("123"); // isi kata
  
}
