#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

String inData;
bool disconnected;
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("connection");
  disconnected = true;
}

void loop() {
  while (Serial.available() > 0) {
    if (disconnected) {
      lcd.clear();
      disconnected = false;
    }
    char recived = Serial.read();
    inData += recived;

    if (recived == '\'') {
      inData.remove(inData.length() - 1, 1);
      if (inData == "DIS") {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Disconnected!");
        disconnected = true;
      } else {
        clearName();
        lcd.setCursor(0,0);
        lcd.print("CPU " + inData);
      }
      inData = "";
    }

    if (recived == '^') {
      inData.remove(inData.length() - 1, 1);
      clearName();
      lcd.setCursor(0,0);
      lcd.print("GPU " + inData);
      inData = "";
    }

    if (recived == '*') {
      inData.remove(inData.length() - 1, 1);
      clearTemp();
      lcd.setCursor(13,0);
      lcd.print(inData + (char)223);
      inData = "";
    }

    if (recived == '#') {
      inData.remove(inData.length() - 1, 1);
      clearClock();
      lcd.setCursor(0,1);
      lcd.print(inData + "MHz");
      inData = "";
    }

    if (recived == '@') {
      inData.remove(inData.length() - 1, 1);
      clearLoad();
      lcd.setCursor(12,1);
      lcd.print(inData + "%");
      inData = "";
    }
  }
}

void clearName() {
  lcd.setCursor(0,0);
  lcd.print("            ");
}

void clearTemp() {
  lcd.setCursor(13,0);
  lcd.print("  ");
}

void clearClock() {
  lcd.setCursor(0,1);
  lcd.print("    ");
}

void clearLoad() {
  lcd.setCursor(12,1);
  lcd.print("    ");
}
