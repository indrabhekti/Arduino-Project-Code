#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
DS3231 rtc(SDA, SCL);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
int Relay = 4;
Time t;

const int OnHour = 11;//SET RELAY ON TIMER
const int OnMin = 57;
const int OffHour = 11;//SET RELAY OFF TIMER
const int OffMin = 58;

void setup() {


  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
  rtc.begin();
  lcd.init();
  lcd.backlight();
  //rtc.setDOW(SATURDAY);     // hari
  //rtc.setTime(12, 11, 00);     // jam format 24
  // rtc.setDate(12, 9, 2020);   // tanggal 12 sept 2020

}

void loop() {
  t = rtc.getTime();
  lcd.setCursor(3, 0);
  lcd.print("RELAY TIMER ");

  lcd.setCursor(0, 1);
  lcd.print("Time:  ");
  lcd.print(rtc.getTimeStr());
  delay(1000);

  //lcd.setCursor(0,1);
  //lcd.print("Date: ");
  //lcd.print(rtc.getDateStr());
  //delay(3000);

  //lcd.setCursor(0,1);
  //lcd.print("Day:    ");
  //lcd.print(rtc.getDOWStr());
  //lcd.print(" ");
  //delay(3000);

  //lcd.setCursor(0,1);
  //lcd.print("Temp:   ");
  //lcd.print(rtc.getTemp());
  //lcd.print(" C");
  //lcd.print(" ");
  //delay(3000);

  if (t.hour == OnHour && t.min == OnMin) {
    lcd.clear();
    digitalWrite(Relay, LOW);
    lcd.setCursor(4, 0);
    lcd.print("RELAY ON   ");
    delay (1000);
    lcd.clear();
  }

  else if (t.hour == OffHour && t.min == OffMin) {
    lcd.clear();
    digitalWrite(Relay, LOW);
    lcd.setCursor(4, 0);
    lcd.print("RELAY OFF");
    delay (1000);
    lcd.clear();
  }
}
