#include <SimpleTimer.h>
      
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial 

#define ESP8266_BAUD 115200
char auth[] = "SL5_Bqv9HskOcnwT0oPrGFAyVn0KCofa";
char ssid[] = "HadiFamily"; // isi nama network
char pass[] = "Aisyaka2004"; // isi pass wifi, kalau open network isi ""
ESP8266 wifi(&EspSerial);

BlynkTimer timer;

void setup();

// Set ESP8266 baud rate
EspSerial.begin(ESP8266_BAUD);
delay(10);

// BLYNk

Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);

timer.setInterval(2000L, myTimerEvent);


void loop() {

if (Blynk.connected()) {  
  Blynk.run();  
  }
  else {
  Blynk.connectWifi(ssid, pass);
  if (WiFi.status() == WL_CONNECTED){
        Blynk.config(auth);
        Blynk.connect();  
    }    
  }

 timer.run(); 

}
