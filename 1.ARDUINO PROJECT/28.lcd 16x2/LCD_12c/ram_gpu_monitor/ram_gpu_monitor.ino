#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); //Change address if this is not applicable
void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
void loop(){
  if (Serial.available()) {
    delay(100);
    lcd.setCursor(0, 0);
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
  }
}
