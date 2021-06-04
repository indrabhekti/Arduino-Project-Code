

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    

char auth[] = "SL5_Bqv9HskOcnwT0oPrGFAyVn0KCofa"; //auth blynk
 
/* WiFi credentials */
char ssid[] = "Kelg_Hadie"; // isi nama network
char pass[] = "Vitri1972" ; // isi pass wifi, kalau open network isi "";


 
SimpleTimer timer;
 
int mq135 = A0; // m135 pada A0
int data = 0; 
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Inisiasi SimpleTimer
  Blynk.run();
}
 
/***************************************************
 void sensor
 **************************************************/
void getSendData()
{
data = analogRead(mq135); 
  Blynk.virtualWrite(V12, data); //virtual pin V12
 
  if (data > 600 )
  {
    Blynk.notify("gas terdeteksi !!!"); 
  }
 
}
