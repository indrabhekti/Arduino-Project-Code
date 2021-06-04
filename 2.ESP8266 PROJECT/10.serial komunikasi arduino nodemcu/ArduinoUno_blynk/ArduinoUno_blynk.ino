#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno (3, 2);

int led = 13;

void setup() {
  Serial.begin(9600);
  ArduinoUno.begin(4800);
  pinMode(led, OUTPUT);
}
void loop() {
  while (ArduinoUno.available() > 0) {
    int val = ArduinoUno.parseInt();
    if (ArduinoUno.read() == '\n') {
      Serial.println(val);
      if (val == HIGH) {
        digitalWrite(led, HIGH);
      }
      else {
        digitalWrite(led, LOW);
      }
    }
  }
}
