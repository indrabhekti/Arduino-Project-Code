#include <LiquidCrystal.h> //mengincludekan library LCD
 
//untuk urutannya RS, E, 4, 5, 6, 7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //pin yang disambungkan antara arduino dengan LCD
 
void setup()
{
//prosedur pemanggilan fungsi LCD
lcd.begin(16, 2);//16 = Baris, 2 = kolom
lcd.print("tes lcd");
}
 
void loop() {
}
