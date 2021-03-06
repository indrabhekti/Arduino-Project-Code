#include <Wire.h>

const byte slaveId = 4;

void setup()
{
  Wire.begin(slaveId); 
  Wire.onReceive(receiveEvent);
 
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);    
}

void loop()
{
}

void receiveEvent(int howMany)
{
  char inChar;
  
  while(Wire.available() > 0)
  {
    inChar = Wire.read();  
    
    if (inChar == 'H')
    {
      digitalWrite(13, HIGH);
    }
    else if (inChar == 'L')
    {
      digitalWrite(13, LOW);
    }
  }
}
