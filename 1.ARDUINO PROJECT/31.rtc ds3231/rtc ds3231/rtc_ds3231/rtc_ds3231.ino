#include <DS3231.h>

DS3231  rtc(SDA, SCL);

void setup()
{
 
  Serial.begin(115200);
  
  rtc.begin();
  
  
 // rtc.setDOW(WEDNESDAY);     // hari
  //rtc.setTime(9, 31, 0);     // jam format 24 
 //rtc.setDate(8, 1, 2019);   // tanggal 4 januari 2019
}

void loop()
{
  // print hari
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // print tanggal
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // print waktu
  Serial.println(rtc.getTimeStr());
  
  // delay 1 s
  delay (1000);
}
