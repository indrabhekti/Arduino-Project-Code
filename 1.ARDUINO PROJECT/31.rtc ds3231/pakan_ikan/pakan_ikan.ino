#define pinServoMakanan               A0
   
#define waktuBukaServo                3000//milidetik
#define servoBuka                     20//derajat
#define servoTutup                    60//derajat

   // set waktu saja (0,1,1, jam, menit,detik,0)
#define waktuMakan1                   DateTime(0, 1, 1,  8, 58, 0, 0)//jam 8 pagi 
#define waktuMakan2                   DateTime(0, 1, 1, 8, 60, 0, 0)//jam 5 sore
   
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Sodaq_DS3231.h"
#include <Servo.h>
   

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

Servo servoMakanIkan;
   
byte detikSebelumnya;
char buf[17];
 
   
void setup() {
  Serial.begin(9600);
  Serial.println("Pemberi pakan ikan otomatis");

     
  servoMakanIkan.attach(pinServoMakanan);
  servoMakanIkan.write(servoTutup);
   
  Wire.begin();
  rtc.begin();
  // hilangkan ( // date time dan // rtc.setdatetime) lalu upload ,setelah itu upload ulang dengan mengembalikan (//) dari keduanya
 // DateTime dt(2020, 10, 24, 8, 30, 0, 7); // set tanggal dan waktu (format): tahun, bulan tanggal, jam, menit, detik, hari (1=minggu, 7=sabtu)
 // rtc.setDateTime(dt);
   
  lcd.begin();
   
  lcd.backlight();
   
  lcd.print("Pemberi ");
  lcd.setCursor(0, 1);
  lcd.print("pakan ikan");
  delay(3000);
  lcd.clear();
   
  Serial.println("Sistem mulai");
  sprintf(buf, "Set waktu 1 = %02d:%02d (%lu)", waktuMakan1.hour(), waktuMakan1.minute(), waktuMakan1.get());
  Serial.println(buf);
  sprintf(buf, "Set waktu 2 = %02d:%02d (%lu)", waktuMakan2.hour(), waktuMakan2.minute(), waktuMakan2.get());
  Serial.println(buf);
}
   
void loop() {
   
  DateTime now = rtc.now();
  if (detikSebelumnya != now.second())
  {
    sprintf(buf, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
    lcd.setCursor(4, 0);
    lcd.print(buf);
    Serial.print(buf);
   
    detikSebelumnya = now.second();
   
    uint32_t epoch = now.get() % 86400;//hanya jam menit detik
   
    if ((epoch == waktuMakan1.get()) ||
        (epoch == waktuMakan2.get()))
    {
      char buf[17];
      sprintf(buf, "Pakan = %02d:%02d", now.hour(), now.minute());
      lcd.setCursor(0, 1);
      lcd.print(buf);
      Serial.println(buf);
   
      servoMakanIkan.write(servoBuka);
      delay(waktuBukaServo);
      servoMakanIkan.write(servoTutup);
   
    }
  }
}
