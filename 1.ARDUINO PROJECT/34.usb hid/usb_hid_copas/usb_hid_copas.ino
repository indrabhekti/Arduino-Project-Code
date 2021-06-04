#include <Keyboard.h>
int cutPin   = 2;
int copyPin  = 3;
int pastePin = 4;

void setup() {
  pinMode(cutPin, INPUT);
  pinMode(copyPin, INPUT);
  pinMode(pastePin, INPUT);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(cutPin)   == HIGH) { cut();   }
  if (digitalRead(copyPin)  == HIGH) { copy();  }
  if (digitalRead(pastePin) == HIGH) { paste(); }
}

void pressCtrl() {
  Keyboard.press(KEY_LEFT_CTRL);
}

void pressShift() {
  Keyboard.press(KEY_LEFT_SHIFT);
}

void cut() {
  pressCtrl();
  Keyboard.write('x');
  Keyboard.releaseAll();
}

void copy() {
  pressCtrl();
  Keyboard.write('c');
  Keyboard.releaseAll();
}

void paste() {
  pressCtrl();
  Keyboard.write('v');
  Keyboard.releaseAll();
}
