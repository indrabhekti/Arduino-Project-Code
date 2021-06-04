#include <OneWire.h>

#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>


const int trigPin = 12;
const int echoPin = 11;
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int LED1 = 8;
const int LED2 = 7;
const int LED3 = 6;
const int LED4 = 5;
const int LED5 = 4;
const int LED6 = 3;
const int LED7 = 2;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);

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

// Prints jarak
Serial.print("JARAK: ");
Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("JARAK: ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print("");
  delay (500);

  

  if ( distance <= 10 )
  {
    digitalWrite(LED1, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 15 )
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 30 )
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 55 )
  {
    digitalWrite(LED4, HIGH);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }
  if ( distance <= 60 )
  {
    digitalWrite(LED5, HIGH);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 70 )
  {
    digitalWrite(LED6, HIGH);
  }
  else
  {
    digitalWrite(LED6, LOW);
  }
  if ( distance <= 85 )
  {
    digitalWrite(LED7, HIGH);
  }
  else
  {
    digitalWrite(LED7, LOW);
  }
}
