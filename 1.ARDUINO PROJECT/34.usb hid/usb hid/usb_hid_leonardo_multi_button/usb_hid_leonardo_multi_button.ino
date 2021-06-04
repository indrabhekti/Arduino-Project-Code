#include <Keyboard.h>
int buttonPin1 = 2;  // Set a button to any pin
int buttonPin2 = 3;
void setup()
{
  pinMode(buttonPin1, INPUT); 
   pinMode(buttonPin2, INPUT);
  digitalWrite(buttonPin1, HIGH);  
  digitalWrite(buttonPin2, HIGH); 
}

void loop()
{
  if (digitalRead(buttonPin1) == 0)  // if the button goes low
  {
    Keyboard.println("195090807111006");  // send a 'z' to the computer via Keyboard HID
    delay(1000);  // delay so there aren't a kajillion z's
  }

   if (digitalRead(buttonPin2) == 0)  // if the button goes low
  {
    Keyboard.println("wijaya18");  // send a 'z' to the computer via Keyboard HID
    delay(1000);  // delay so there aren't a kajillion z's
  }
}
