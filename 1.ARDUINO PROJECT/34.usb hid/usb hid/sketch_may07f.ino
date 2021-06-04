#include "HID-Project.h"
char ctrlKey = KEY_LEFT_CTRL;

byte h = 0, v = 0;         // variables used in for loops
const int period = 50;     // A little delay to avoid errors.
int kdelay = 0;            // Non Blocking Delay
const byte rows = 4;       // Rows in Keypad
const byte columns = 4;    // Columns in Keypad
const byte Output[rows] = {8, 9, 10, 11}; //Row connceted to Arduino Pins
const byte Input[columns] = {2, 3, 4, 5}; //Columns connected to Arduino Pins
void setup()
{
  for (byte i = 0; i < rows; i++) //Loop to declare output pins.
  {
    pinMode(Output[i], OUTPUT);
  }
  for (byte s = 0; s < columns; s++) // Loop to decalre Input pins, Initial Pulledup.
  {
    pinMode(Input[s], INPUT_PULLUP);
  }
  Serial.begin(9600);         // Initializing Serail communication.
}
void loop()
{
  if (millis() - kdelay > period) //used to make non-blocking delay
  {
    kdelay = millis(); //capture time from millis function
    switch (keypad())     //Switch to get which button is pressed.
    {
      case 0:
        Keyboard.press(KEY_LEFT_CTRL); // Command key in Mac, use KEY_LEFT_CTRL for Pc
        Keyboard.press('c');
        delay(500);
        Keyboard.releaseAll();
        break;
      case 1:
        Keyboard.press(KEY_LEFT_CTRL); // Command key in Mac, use KEY_LEFT_CTRL for Pc
        Keyboard.press('v');
        delay(500);
        Keyboard.releaseAll();
        break;
      case 2:

        Keyboard.press(KEY_LEFT_CTRL); // Command key in Mac, use KEY_LEFT_CTRL for Pc
        Keyboard.press('x');
        delay(500);
        Keyboard.releaseAll();
        break;
      case 3:
        Keyboard.press(KEY_LEFT_CTRL); // Command key in Mac, use KEY_LEFT_CTRL for Pc
        Keyboard.press('z');
        delay(500);
        Keyboard.releaseAll();
        break;
      case 4:
        Consumer.write(MEDIA_PLAY_PAUSE);
        delay(150);
        Keyboard.releaseAll();
        break;
      case 5:
        Consumer.write(MEDIA_VOLUME_UP);
        delay(150);
        Keyboard.releaseAll();
        break;
      case 6:
        Consumer.write(MEDIA_VOLUME_DOWN);
        delay (150);
        Keyboard.releaseAll();
        break;
      case 7:
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_F4);
        delay (500);
        Keyboard.releaseAll();
        break;
      case 8:
        Serial.println(7);
        break;
      case 9:
        Serial.println(8);
        break;
      case 10:
        Serial.println(9);
        break;
      case 11:
        Serial.println("C");
        break;
      case 12:
        Serial.println("*");
        break;
      case 13:
        Serial.println(0);
        break;
      case 14:
        Serial.println("#");
        break;
      case 15:
        Serial.println("D");
        break;
      default:
        ;
    }
  }
}

// Below function is used to detect which button is pressed.

byte keypad()
{
  static bool no_press_flag = 0;
  for (byte x = 0; x < columns; x++)
  {
    if (digitalRead(Input[x]) == HIGH);
    else
      break;
    if (x == (columns - 1))
    {
      no_press_flag = 1;
      h = 0;
      v = 0;
    }
  }
  if (no_press_flag == 1)
  {
    for (byte r = 0; r < rows; r++)
      digitalWrite(Output[r], LOW);
    for (h = 0; h < columns; h++)
    {
      if (digitalRead(Input[h]) == HIGH)
        continue;
      else
      {
        for (v = 0; v < rows; v++)
        {
          digitalWrite(Output[v], HIGH);
          if (digitalRead(Input[h]) == HIGH)
          {
            no_press_flag = 0;
            for (byte w = 0; w < rows; w++)
              digitalWrite(Output[w], LOW);
            return v * 4 + h;
          }
        }
      }
    }
  }
  return 50;
}
