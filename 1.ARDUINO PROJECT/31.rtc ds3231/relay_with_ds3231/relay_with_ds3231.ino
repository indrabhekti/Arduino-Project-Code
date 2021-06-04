#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

int Relay = 4;

DS3231  rtc(SDA, SCL);
Time t;

const int OnHour = 10;//SET RELAY ON TIMER
const int OnMin = 51;
const int OffHour = 10;//SET RELAY OFF TIMER
const int OffMin = 52;

void setup() {

  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);

  lcd.init();
  rtc.begin(); // Initialize the rtc object

  lcd.backlight();

 // rtc.setDOW(FRIDAY);
 /// rtc.setTime(10, 50, 0);    //SET TIME
 /// rtc.setDate(14, 06, 2019);
//

}

void loop() {
  t = rtc.getTime();
  {
    lcd.println(rtc.getDOWStr());
    lcd.setCursor(0, 0);
    lcd.println("");
    
  }

  // Send date

  {
    lcd.print(rtc.getDateStr());
    lcd.setCursor(0, 1);
    lcd.print(" ");
    delay (1000);
  }
  // Send time

  {
    lcd.println(rtc.getTimeStr());
    lcd.setCursor(0, 1);
    lcd.println(" ");
    delay (1000);
  }


  if (t.hour == OnHour && t.min == OnMin) {
    digitalWrite(Relay, HIGH);
    lcd.setCursor(1, 0);
    lcd.println(" MOTOR ON   ");
    delay (1000);
  }

  else if (t.hour == OffHour && t.min == OffMin) {
    digitalWrite(Relay, LOW);
    lcd.setCursor(1, 0);
    lcd.println("MOTOR OFF");
    delay (1000);
  }
}
