#include <PZEM004Tv30.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>  

char auth[] = "SL5_Bqv9HskOcnwT0oPrGFAyVn0KCofa";

char ssid[] = "Kelg_Hadie"; // isi nama network
char pass[] = "Vitri1972" ; // isi pass wifi, kalau open network isi ""
        
PZEM004Tv30 pzem(14, 12);// d5= rx d6 tx

float Power ,Energy , Voltase , Current,frequency , pf;

void setup() {
Serial.begin(9600);
Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);        

}
void loop() {
  // put your main code here, to run repeatedly:
Power = pzem.power ();// pzem power nilai
if (isnan(Power)){
  Serial.println ("GAGAL MEMBACA POWER");
}
else {
  Serial.print ( "Power :  ");
  Serial.print (Power) ;
  Serial.println ("kW");
}
Energy = pzem.energy ();// pzem power nilai
if (isnan(Energy)){
  Serial.println ("GAGAL MEMBACA ENERGY");
}
else {
  Serial.print ( "Energy :  ");
  Serial.print (Energy) ;
  Serial.println ("kWh");
}

Voltase = pzem.voltage ();// pzem power nilai
if (isnan(Voltase)){
  Serial.println ("GAGAL MEMBACA VOLTASE");
}
else {
  Serial.print ( "Voltase :  ");
  Serial.print (Voltase) ;
  Serial.println ("V");
}


Current = pzem.current ();// pzem power nilai
if (isnan(Current)){
  Serial.println ("GAGAL MEMBACA Arus");
}
else {
  Serial.print ( "Current :  ");
  Serial.print (Current) ;
  Serial.println ("A");
}

frequency = pzem.frequency();
if (isnan(frequency)){
  Serial.println ("GAGAL MEMBACAfrq");
}
else {
  Serial.print ( "frequency :  ");
  Serial.print (frequency) ;
  Serial.println ("Hz");
}

pf = pzem.pf();
if (isnan(pf)){
  Serial.println ("GAGAL MEMBACA pf");
}
else {
  Serial.print ( "pf :  ");
  Serial.print (pf) ;
  Serial.println ("Hz");
}

 Serial.println ();

Blynk.virtualWrite (V0,Power);
Blynk.virtualWrite (V1,Energy);
Blynk.virtualWrite (V2,Voltase);
Blynk.virtualWrite (V3,Current);
Blynk.virtualWrite (V4,frequency);
Blynk.virtualWrite (V5,pf);
Blynk.run();


 
 delay (1000);  
}
