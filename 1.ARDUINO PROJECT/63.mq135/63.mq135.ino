
#include <SimpleTimer.h>

 
SimpleTimer timer;
 
int mq135 = A0; // m135 pada A0
int data = 0; 
void setup() 
{
  Serial.begin(115200);
  
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Inisiasi SimpleTimer
 
}
 
/***************************************************
 void sensor
 **************************************************/
void getSendData()
{
data = analogRead(mq135); 
 Serial.print("nilai"); Serial.print (data);
 
  if (data > 600 )
  {
 Serial.println ("gas terdeteksi");
  }
 
}
