
#include <Wire.h>

void setup()
{
  Wire.begin(); 
}

void loop()
{
  Wire.beginTransmission(1);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(1);
  Wire.write('L');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(2);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(2);
  Wire.write('L');
  Wire.endTransmission();
  
 
  delay(500);

   Wire.beginTransmission(3);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(3);
  Wire.write('L');
  Wire.endTransmission();
  
 
  delay(500);

  
   Wire.beginTransmission(4);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(4);
  Wire.write('L');
  Wire.endTransmission();
  
 
  delay(500);

  
}
