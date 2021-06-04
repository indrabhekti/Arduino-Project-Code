
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
LiquidCrystal_I2C lcd(0x27, 16, 2);

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
double latitude, longitude;

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ArduGPS Ublox 6M");
  lcd.setCursor(3, 1);
  lcd.print("dafa wijaya");
  delay(8000);
  lcd.clear();
}

void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("Gps tidak terdeteksi, tolong cek lagi dalam alokasi pin."));
    while (true);
  }
}

void displayInfo()
{
  Serial.print(F("Lokasi: "));
  if (gps.location.isValid())
  {
    Serial.println("Latitude,Longitude:");

    Serial.print("http://maps.google.com/maps?q=");
    Serial.print(gps.location.lat(), 6);
    lcd.setCursor(0, 0);
    lcd.print("lat=");
    lcd.setCursor(4, 0);
    lcd.print(gps.location.lat(), 6);
    Serial.print(",");// print latitude
    Serial.println(gps.location.lng(), 6);
    lcd.setCursor(0, 1);
    lcd.print("long=");
    lcd.setCursor(5, 1);
    lcd.print(gps.location.lng(), 6);
    delay (10000);
    lcd.clear ();
    String
    link_fix = "http://maps.google.com/maps?q=";
    String lat_fix = "";
    String lot_fix = "";
    String koma = ",";
    lat_fix = String(gps.location.lat(), 6);
    lot_fix = String(gps.location.lng(), 6);

  }
  else
  {
    Serial.print(F("INVALID"));
    lcd.setCursor(0, 0);
    lcd.print(F("INVALID"));
  }

  Serial.print(F("  Tanggal "));
  if (gps.date.isValid())
  {
    lcd.setCursor(0, 0);
    lcd.print ("date=");
    lcd.setCursor(6, 0);
    Serial.print(gps.date.month());
    lcd.print(gps.date.month());
    Serial.print(F("/"));
    lcd.print(F("/"));
    Serial.print(gps.date.day());
    lcd.print(gps.date.day());
    Serial.print(F("/"));
    lcd.print(F("/"));
    Serial.print(gps.date.year());
    lcd.print(gps.date.year());
    delay (10000);
    lcd.clear ();
  }
  else
  {
    Serial.print(F("Tidak valid"));

  }


  Serial.println();
}
