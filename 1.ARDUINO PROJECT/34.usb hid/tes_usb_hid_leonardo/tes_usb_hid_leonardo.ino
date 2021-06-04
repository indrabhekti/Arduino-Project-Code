#include <Keyboard.h>
void setup() {
  // put your setup code here, to run once:
pinMode (2,INPUT);
digitalWrite (2,HIGH);

Keyboard.begin ();

}
void loop() {
  // put your main code here, to run repeatedly:

while (digitalRead (2))
{
}
Keyboard.println ("usb hid leonardo ");
delay (1000);
Keyboard.println ("tes usb hid ");
delay (1000);


Keyboard.write (48);
delay(2500);
Keyboard.releaseAll();
}
