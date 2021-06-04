#include <PZEM004Tv30.h>
PZEM004Tv30 pzem(14, 12);// d5= rx d6 tx

float Power ,Energy , Voltase , Current;

void setup() {
Serial.begin(9600);

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
 Serial.println ();
 delay (1000);
}
