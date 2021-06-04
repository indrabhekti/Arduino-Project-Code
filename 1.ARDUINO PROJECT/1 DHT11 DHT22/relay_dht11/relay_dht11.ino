#include "DHT.h"

#define DHTPIN 11                   // what digital pin DHT11 is connected to
#define DHTTYPE DHT11              // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const int relayPin = 8;           // what digital pin relay module is connected to

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(relayPin, OUTPUT); 
  digitalWrite(relayPin, LOW);      // Initialising to 0V as the relay module is high-level trigger
}

void loop() {
  delay(2000);                      // Wait 2 seconds between measurements.
  float t = dht.readTemperature();  // Read temperature as Celsius (the default)
  if (isnan(t)) {                   // Check if any reads failed and exit early (to try again).
    return;
  }
  Serial.println(t);                // Plot temperature values
  Serial.print(" ");
  if (t > 29) {                     // if temperature > 32 degrees Celsius
    digitalWrite(relayPin, HIGH);   // turn A/C on
    delay(500);    
  }
  else {
    digitalWrite(relayPin, LOW);   // else turn it off
    delay(500);
  }  
}
