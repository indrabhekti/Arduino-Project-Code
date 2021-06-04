#include<dht11.h>      // Including library for dht

#include <LiquidCrystal_I2C.h> // library i2c
LiquidCrystal_I2C lcd(0x27,16,2); 

#define DHT11PIN 8

dht11 DHT11;


byte degree[8] = 
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };

void setup()
{
 lcd.init();
 lcd.backlight(); 
 lcd.createChar(1, degree);
 lcd.clear();
 lcd.print("   Humidity   ");
 lcd.setCursor(0,1);
 lcd.print("  Measurement ");
 delay(2000);
 lcd.clear();
  lcd.setCursor(2,0);
 lcd.print("DAFA WIJAYA ");
 delay(2000);
}

void loop()
{
  DHT11.read(DHT11PIN);
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(DHT11.humidity);   // printing Humidity on LCD
  lcd.print(" %");
  lcd.setCursor(0,1);
  lcd.print("Temperature:");
  lcd.print(DHT11.temperature);   // Printing temperature on LCD
  lcd.write(1);
  lcd.print("C");
  delay(500);
}
