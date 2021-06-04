#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define Password_Length 8

int signalPin = 12;

char Data[Password_Length];
char Master[Password_Length] = "1234567";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;


char hexaKeys[ROWS][COLS] = {
  {'4', '8', '#', 'D'},
  {'3', '7', '*', 'C'},
  {'2', '6', '0', 'B'},
  {'1', '5', '9', 'A'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {8, 9, 10, 11};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(signalPin, OUTPUT);
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  customKey = customKeypad.getKey();
  if (customKey) {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  if (data_count == Password_Length - 1) {
    lcd.clear();

    if (!strcmp(Data, Master)) {
      lcd.print("Correct");
      digitalWrite(signalPin, HIGH);
    }
    else {
      lcd.print("Incorrect");
      delay(1000);
      digitalWrite(signalPin, LOW);
    }

    lcd.clear();
    clearData();
  }
}

void clearData() {
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}
