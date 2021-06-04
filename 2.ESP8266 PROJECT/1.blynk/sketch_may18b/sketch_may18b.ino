#define BLYNK_PRINT Serial        
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h>        
char auth[] = "authtocken"; // PASTE YOUR AUTHENTICATION CODE HERE        
// Your WiFi credentials.        
char ssid[] = "ssid"; //WIFI NAME        
char pass[] = "password"; //PASSWORD        
void setup()        
{        
 Serial.begin(9600);        
 Blynk.begin(auth, ssid, pass);        
}       
 void setup_wifi() {
      delay(10);
      WiFi.begin(ssid, pass);
      if (WiFi.status() != WL_CONNECTED) {
         Blynk.disconnect();
        delay(1000);
      }
      else {
        Blynk.connected();

      }
    }

 timer.setInterval(9000L, setup_wifi);

 void reconnectBlynk() {
    if (!Blynk.connected()) {
      digitalWrite(17,LOW);
   delay (2000);
   digitalWrite (17,HIGH);
    if(Blynk.connect())  {
   
   BLYNK_LOG("Reconnected");}
   
   else{
    digitalWrite(17,HIGH);
      BLYNK_LOG("Not connected");
    }
    }
  }

void loop()
 
  
    {

 if (Blynk.connected()) {
    Blynk.run();}

1
