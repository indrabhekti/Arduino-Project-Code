#include <LiquidCrystal.h>
int vib = 2;
int buzz = 8;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //pin yang disambungkan antara arduino dengan LCD
 
void setup() {
  // put your setup code here, to run once:
  pinMode (vib, INPUT);
  pinMode (buzz, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
lcd.print("PENDETEKSI GEMPA ");
delay(5000);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  // put your main code here, to run repeatedly:
  int val; val = digitalRead (vib);
  if (val == 1) {

    lcd.setCursor(0,0);
  lcd.print("   TERDETEKSI ");
    lcd.setCursor(2, 1); //
  lcd.print("   GEMPA");
         // buzzer (pada pin 2) berbunyi dengan 2900 Hz selama 200 ms
                   //delay selama 300 ms
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
        tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);
    tone(8, 2900, 200);
    delay(300);


  }
}
