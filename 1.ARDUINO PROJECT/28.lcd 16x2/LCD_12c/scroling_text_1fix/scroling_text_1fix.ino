  
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
  
//----------------------------------
int Li          = 16;
int Lii         = 0; 
int Ri          = -1;
int Rii         = -1;

void setup(){
   lcd.init();
  lcd.backlight();                         // start the LCD library
  
}

 

void loop(){
  lcd.setCursor(0,0);             
  lcd.print("  DAFA WIJAYA ");  
  lcd.setCursor(0, 1);
  lcd.print(Scroll_LCD_Left("TES SCROLLING TEXT 1234567890")); // ganti left atau right nya

   delay(200);
}




//untuk scroll dari kiri
String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}

void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
}


//scroll dari kanan
String Scroll_LCD_Right(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  if (Rii<1){
    Ri  = StrProcess.length();
    Rii = Ri-16;
  }
  result = StrProcess.substring(Rii,Ri);
  Ri--;
  Rii--;
  return result;
}

void Clear_Scroll_LCD_Right(){
  Ri=-1;
  Rii=-1;
}
