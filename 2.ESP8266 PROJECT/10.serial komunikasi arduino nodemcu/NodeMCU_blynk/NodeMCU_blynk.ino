#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
// ================= CONNECT TO WIFI ================
char auth[] = "SL5_Bqv9HskOcnwT0oPrGFAyVn0KCofa";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Kelg_Hadie";
char pass[] = "Vitri1972";
int a;

SoftwareSerial NodeMCU(D2, D1); //d2 ke 2 d1 ke 3

void setup() {
  Serial.begin(9600);
  NodeMCU.begin(4800);
  Blynk.begin(auth, ssid, pass);
  pinMode(D2, INPUT);
  pinMode(D1, OUTPUT);
}

BLYNK_WRITE(V0)
{
  a = param.asInt();
  NodeMCU.print(a);
  NodeMCU.println("\n");
  Serial.println(a);
}

void loop() {
  Blynk.run();
}
