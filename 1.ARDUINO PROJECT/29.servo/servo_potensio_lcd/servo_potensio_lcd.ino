#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int nilai;
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  nilai = analogRead(A0);
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  Serial.print("POTENSIO = ");
  Serial.print(nilai);
  Serial.print("  ");
  Serial.print("SUDUT SERVO = ");
  Serial.println(val);
  lcd.setCursor(0, 0);
  lcd.print("POTENSIO = ");
  lcd.setCursor(11, 0);
  lcd.print(nilai);  
  lcd.print(" ");   
  lcd.setCursor(0, 1);
  lcd.print("SUDUT SERVO = ");
  lcd.setCursor(12
  , 1);
  lcd.print(val);
  lcd.print(" ");
  delay(50);                           // waits for the servo to get there
}
