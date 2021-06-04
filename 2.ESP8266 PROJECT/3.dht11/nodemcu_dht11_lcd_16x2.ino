

#define BLYNK_PRINT Serial
 
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// dapetkan Auth Token pada the Blynk App.

char auth[] = "SL5_Bqv9HskOcnwT0oPrGFAyVn0KCofa";
 
// NAMA WIFI DAN PASSWORD
// Isi password "" untuk open networks.
char ssid[] = "Kelg_Hadie";
char pass[] = "Vitri1972";
 
#define DHTPIN 0          // D3

        
LiquidCrystal_I2C lcd(0x27,16,2);

#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}

void setup()
{  
  lcd.init();
  lcd.backlight();
  dht.begin();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  Serial.begin(9600);
 Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  
  timer.setInterval(1000L, sendSensor);
}

  void loop() {

  delay(500);
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.print("ERROR");
    return;
  }
  lcd.setCursor(5,0);
  lcd.print(t);
  lcd.setCursor(9,1);
  lcd.print(h);
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}
}
