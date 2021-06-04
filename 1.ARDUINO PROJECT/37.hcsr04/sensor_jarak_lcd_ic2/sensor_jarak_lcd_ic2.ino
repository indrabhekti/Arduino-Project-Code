#include <OneWire.h>

#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>


const int trigPin = 9;
const int echoPin = 10;

LiquidCrystal_I2C lcd(0x27, 16, 2);
// defines variables
long duration;
int distance;
int safetyDistance;

void setup() 
{
  lcd.init();
  lcd.backlight();
//awal lcd akan muncul tulisan di bawah ini
lcd.setCursor(0,0);
lcd.print("PENGUKUR JARAK "); //kata pada baris pertama lcd 16x2
lcd.setCursor(2,1);
lcd.print("BY DAFA WIJAYA"); //kata pada baris ke dua lcd 16x2
delay (5000);

pinMode(trigPin, OUTPUT); // Sets trigPin menjadi Output
pinMode(echoPin, INPUT); // Sets echoPin menjadi Input

Serial.begin(9600); // memulai serial komunikasi
}

void loop() 
{
lcd.clear();
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets trigPin pada HIGH untuk 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads  echoPin, merubah jarak tempuh gelombang suara di microseconds
duration = pulseIn(echoPin, HIGH);

// kalkulasi
distance= duration*0.034/2;

safetyDistance = distance;

// Prints jarak
Serial.print("JARAK: ");
Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("JARAK: ");
  lcd.print(distance);
  lcd.print("  cm");
  lcd.setCursor(0,1);
  lcd.print(" ");
  delay (500);
}
