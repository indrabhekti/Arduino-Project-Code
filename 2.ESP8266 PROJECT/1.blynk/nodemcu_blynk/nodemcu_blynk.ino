
#define BLYNK_PRINT Serial        
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h>        
char auth[] = "SL5_Bqv9HskOcnwT0oPrGFAyVn0KCofa";

char ssid[] = "Kelg_Hadie"; // isi nama network
char pass[] = "Vitri1972" ; // isi pass wifi, kalau open network isi ""
        
void setup()        
{        
 Serial.begin(9600);        


Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);        
}        
void loop()        
{        
 Blynk.run();        
}
