

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


 
//PILIH TYPE SENSOR DHT 
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301
 
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // atau dht.readTemperature(true) untuk Fahrenheit
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t); // suhu di blynk v5
  Blynk.virtualWrite(V6, h); // kelembaban di blynk v6
}
 
void setup()
{
 
  lcd.begin();
  lcd.backlight();
  dht.begin();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  Serial.begin(9600);
Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,10), 8442);
 
  dht.begin();
 
 
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
