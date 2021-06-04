
#include "HID-Project.h"
char ctrlKey = KEY_LEFT_CTRL;
const int buttons[] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 2; i < 9; ++i) {
    if (digitalRead(i) == LOW) {
      // software de-bounce improves accuracy
      delay(10);
      if (digitalRead(i = 3) == LOW) {
        Keyboard.press(KEY_LEFT_CTRL); // Command key in Mac, use KEY_LEFT_CTRL for Pc
        Keyboard.press('v');
        delay(500);
        Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      }
      if (digitalRead(i = 2) == LOW) {
        Keyboard.press(KEY_LEFT_CTRL); // Command key in Mac, use KEY_LEFT_CTRL for Pc
        Keyboard.press('c');
        delay(500);
        Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      }
      if (digitalRead(i = 4) == LOW) {

        Consumer.write(MEDIA_PLAY_PAUSE);

        delay(500);
        Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      }
      if (digitalRead(i = 5) == LOW) {

        Consumer.write(MEDIA_VOLUME_UP);
        delay(150);
        Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      }
      if (digitalRead(i = 6) == LOW) {
        Consumer.write(MEDIA_VOLUME_DOWN);
        delay (150);
        Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      }
      if (digitalRead(i = 7) == LOW) {
        Keyboard.print ("dafanur18@student.ub.ac.id ");
        delay (1000);
        Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      }
      if (digitalRead(i = 8) == LOW) {
        Keyboard.println ("wijaya18");
        delay (1000);
        Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      }
    }
  }
}
