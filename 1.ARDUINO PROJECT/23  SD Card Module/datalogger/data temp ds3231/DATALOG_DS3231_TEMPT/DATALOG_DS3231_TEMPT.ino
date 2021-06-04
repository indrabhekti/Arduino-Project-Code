#include <Wire.h>
#include <DS3231.h> //memasukan library DS3231
#include <SPI.h>
#include <SD.h>

DS3231  rtc(SDA, SCL); //prosedur pembacaan I2C
File myFile;

void setup()
{
  //set komunikasi baut di serial monitor pada kecepatan 9600
  Serial.begin(9600);
  //menuliskan data di serial monitor
  Serial.println("Trial Data Logger Arduino");
  Serial.println("dafa nur isa wijaya");
  delay(3000); //Waktu jeda

  //prosedur pembacaan RTC DS3231
  rtc.begin();

  //setting pertama download program
 // rtc.setDate(13, 11, 2020);   //tgl buln tahub
  //rtc.setTime(7, 11, 00);     //menset jam7:11:00
  //rtc.setDOW(6);     //menset hari "JUMAT"

  Serial.println("Read MicoSd Card");
  delay(1000);

  if (!SD.begin(4))
  {
    Serial.println("Failed read microsd card on module!");
    return;
  }
  Serial.println("Success read microsd card");
  delay(1000);
}

void loop()
{
  myFile = SD.open("dlog.txt", FILE_WRITE); //Membuka File datalogger.txt
  if (myFile) // jika file tersedia tulis data
  {
    Serial.print(rtc.getDOWStr(1));
    Serial.print(",");
    myFile.print(rtc.getDOWStr(1));
    myFile.print(",");

    Serial.print(rtc.getDateStr());
    Serial.print(" -- ");
    myFile.print(rtc.getDateStr());
    myFile.print(" -- ");

    Serial.println(rtc.getTimeStr());
    Serial.print(" -- ");
    myFile.println(rtc.getTimeStr());
    myFile.print(" -- ");

    Serial.print(" suhu:");
    Serial.println(rtc.getTemp());
    myFile.print(" suhu:");
    myFile.println(rtc.getTemp());
    myFile.close();
  }
  else
  {
    Serial.println("Failed open dlog.txt"); // jika gagal print error
  }
  delay(2000); //total jeda yaitu 5 detik karena proses penulisan data kurang lebih 3 detik
}
