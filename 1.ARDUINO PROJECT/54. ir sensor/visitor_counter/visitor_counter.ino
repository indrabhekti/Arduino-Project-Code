/*lcd 16 x 2 i2c : sda A4
                   scl A5
  ir input       :d9
  ir output      :d8
  relay          :d13               
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
#define in 8
#define out 9
#define fan 13
int count = 0;
void setup()
{
  lcd.begin();
  lcd.backlight ();
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(fan, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
}
void loop()
{
  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  if (in_value == LOW)
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }

  if (out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }


  if (count == 0)
  {
    lcd.clear();
    digitalWrite(fan, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0, 1);
    lcd.print("relay is Off");
    delay(200);
  }

  else
  {
    digitalWrite(fan, HIGH);
  }
}
