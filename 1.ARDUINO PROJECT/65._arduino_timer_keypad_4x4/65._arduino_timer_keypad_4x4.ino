#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//constants for Control Pin

int controlPin = 13;
char currentTimeValue[4];
int currentState = 1;
int timerSeconds = 0;
int lpcnt = 0;

//define the keypad
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line


void setup()
{
  lcd.init(); // initialize the lcd

  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("arduino based");
  lcd.setCursor(0, 1);
  lcd.print("timer with 4x4keypad");
  lcd.setCursor(3, 2);
  lcd.print("by dafa wijaya");
  lcd.setCursor(0, 3);
  lcd.print("====================");

  delay (7000);

  //display main screen
  displayCodeEntryScreen();

  //setup and turn off relay
  pinMode(controlPin, OUTPUT);
  digitalWrite(controlPin, LOW);

  //setup default time to 00:00
  currentTimeValue[0] = '0';
  currentTimeValue[1] = '0';
  currentTimeValue[2] = '0';
  currentTimeValue[3] = '0';
  showEnteredTime();
}

void loop()
{
  int l;
  char tempVal[3];
  char key = keypad.getKey();

  //key pressed and state is 1
  if (int(key) != 0 and currentState == 1) {

    switch (key) {
      case '*':
        relayStatus(false);
        currentTimeValue[0] = '0';
        currentTimeValue[1] = '0';
        currentTimeValue[2] = '0';
        currentTimeValue[3] = '0';
        showEnteredTime();
        currentState = 1;

        lpcnt = 0;
        timerSeconds = 0;
        break;

      case '#':
        tempVal[0] = currentTimeValue[0];
        tempVal[1] = currentTimeValue[1];
        tempVal[2] = 0;

        timerSeconds = atol(tempVal) * 60;

        tempVal[0] = currentTimeValue[2];
        tempVal[1] = currentTimeValue[3];
        tempVal[2] = 0;

        timerSeconds = timerSeconds + atol(tempVal);
        currentState = 2;
        break;

      default:
        currentTimeValue[0] = currentTimeValue[1];
        currentTimeValue[1] = currentTimeValue[2];
        currentTimeValue[2] = currentTimeValue[3];
        currentTimeValue[3] = key;
        showEnteredTime();
        break;
    }
  }

  if (currentState == 2) {
    if (int(key) != 0) {
      if (key == '*') {
        relayStatus(false);
        displayCodeEntryScreen();
        currentTimeValue[0] = '0';
        currentTimeValue[1] = '0';
        currentTimeValue[2] = '0';
        currentTimeValue[3] = '0';
        showEnteredTime();
        currentState = 1;
        lpcnt = 0;
        timerSeconds = 0;
      }
    } else {

      if (lpcnt > 9) {
        lpcnt = 0;
        --timerSeconds;
        showCountdown();

        if (timerSeconds <= 0) {
          currentState = 1;
          relayStatus(false);
          displayCodeEntryScreen();
          showEnteredTime();
        } else {
          relayStatus(true);
        }
      }

      ++lpcnt;
      delay(100);
    }
  }
}

void showEnteredTime()
{
  lcd.setCursor(14, 3);
  lcd.print(currentTimeValue[0]);
  lcd.print(currentTimeValue[1]);
  lcd.print(":");
  lcd.print(currentTimeValue[2]);
  lcd.print(currentTimeValue[3]);
}
void relayStatus(bool state)
{
  if (state)
    digitalWrite(controlPin, HIGH);
  else
    digitalWrite(controlPin, LOW);
}
void showCountdown()
{
  char timest[6]; \


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("********************");
  lcd.setCursor(0, 1);
  lcd.print("** COUNTING DOWN  **");
  lcd.setCursor(8, 2);

  sprintf(timest, "%d:%.2d", (timerSeconds / 60), (timerSeconds - ((timerSeconds / 60) * 60)));
  lcd.print(timest);

  lcd.setCursor(0, 3);
  lcd.print("********************");

}

void displayCodeEntryScreen()
{
  lcd.clear();
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("silahkan setting");
  lcd.setCursor(0, 1);
  lcd.print("waktu dengan format");
  lcd.setCursor(0, 2);
  lcd.print("menit:detik");

}

void clearScreen()
{
  lcd.setCursor(0, 0);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
}
