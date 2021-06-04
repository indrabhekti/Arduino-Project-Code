#include <Servo.h>
#include <Keypad.h>
Servo myservo;  
const byte baris = 4;
const byte kolom = 4;
char Hexa[baris][kolom]={
{'D','C','B','A'},
{'#','9','6','3'},
{'0','8','5','2'},
{'*','7','4','1'}
};
char kunci[5];
char pin;
int hitung=0, i;
byte pinBaris [baris] = {3, 4, 5, 6};
byte pinKolom [kolom] = {7, 8, 9, 10};
Keypad Keypadvar = Keypad(makeKeymap(Hexa), pinBaris, pinKolom, baris, kolom);
void setup() {
Serial.begin(9600);
myservo.attach(2);
}
void loop() {
char Keyvar = Keypadvar.getKey();
if (Keyvar){
  hitung++;
    kunci[hitung] = Keyvar;
     Serial.print(kunci[hitung]);
  Serial.print("  ");
  if (hitung == 4){
    hitung=0;
  if ((kunci[1]=='1') &&(kunci[2]=='4')&&(kunci[3]=='1') &&(kunci[4]=='2')){
  Serial.println("Pin Anda Benar");
  myservo.write(180);
  delay(3000);
  myservo.write(90);
  delay(10);
  }
  else{
    Serial.println("Pin Anda Salah");
      }
    }
  }
}
