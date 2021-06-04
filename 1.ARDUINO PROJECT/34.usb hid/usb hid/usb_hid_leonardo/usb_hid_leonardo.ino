
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
Keyboard.println ("biodata ");
delay (1000);
Keyboard.println ("nama :dafa wijaya");
delay (1000);
Keyboard.println ("instrumentasi ub");
delay (1000);
Keyboard.println ("email :dafanur18@student.ub.ac.id");
delay(1000);
Keyboard.println ("081334946464");
delay (1000);
Keyboard.println ("malang,indonesia");
delay (1000);



Keyboard.releaseAll();

}
