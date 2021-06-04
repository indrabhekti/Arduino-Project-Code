#include <EEPROM.h>
String myData;
char buff[10];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available()>0){
  delay(10);
  char c = Serial.read();
  myData+=c;
}
if (myData.length()>0){
  myData.toCharArray(buff, 10);
  Serial.println(buff);
  EEPROM.put(0,buff);
  myData="";
}
String hasil = EEPROM.get(0,buff);
Serial.println(hasil);
delay(1000);
}
