#include <Wire.h> // I2C library, required for MLX90614
#include <LiquidCrystal_I2C.h>
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

IRTherm therm; // Create an IRTherm object to interact with throughout

const byte LED_PIN = 13; // Optional LED attached to pin 8 (active low)

void setup()
{
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("IR Thermometer");
  Serial.begin(9600); // Initialize Serial to log output
  therm.begin(); // Initialize thermal IR sensor
  therm.setUnit(TEMP_C); // Set the library's units to Farenheit
  // Alternatively, TEMP_F can be replaced with TEMP_C for Celsius or
  // TEMP_K for Kelvin.

  pinMode(LED_PIN, OUTPUT); // LED pin as output
  setLED(LOW); // LED OFF

}

void loop()
{
  setLED(HIGH); //LED on

  // Call therm.read() to read object and ambient temperatures from the sensor.
  if (therm.read()) // On success, read() will return 1, on fail 0.
  {
    // Use the object() and ambient() functions to grab the object and ambient
    // temperatures.
    // They'll be floats, calculated out to the unit you set with setUnit().
    Serial.print("Object: " + String(therm.object(), 2));
    Serial.write(' '); // Degree Symbol
    Serial.println("C");
    lcd.setCursor(0, 0);
    lcd.print("Object: " + String(therm.object(), 2));
    lcd.print(' ');
    lcd.print("C");

    Serial.print("Ambient: " + String(therm.ambient(), 2));
    Serial.write(' '); // Degree Symbol
    Serial.println("C");
    Serial.println();
    lcd.setCursor(0, 1);
    lcd.print("Ambient: " + String(therm.ambient(), 2));
    lcd.print(' ');
    lcd.print("C");
    delay(1000);
    //    lcd.clear();
  }
  setLED(LOW);
  delay(500);
}

void setLED(bool on)
{
  if (on)
    digitalWrite(LED_PIN, LOW);
  else
    digitalWrite(LED_PIN, HIGH);
}
