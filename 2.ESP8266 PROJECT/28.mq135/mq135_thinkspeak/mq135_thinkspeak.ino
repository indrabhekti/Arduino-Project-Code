
#include <ESP8266WiFi.h>
WiFiClient client;
String apiKey = "WSDHHV4RP0Q4TOIO"; // Enter your Write API key from ThingSpeak
const char *ssid = "Kelg_Hadie"; // replace with your wifi ssid and wpa2 key
const char *pass = "Vitri1972";
const char* server = "api.thingspeak.com";

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}
void loop()
{
  float h = analogRead(A0);
  if (isnan(h))
  {
    Serial.println("Failed to read from MQ-135 sensor!");
    return;
  }

  if (client.connect(server, 80)) // "184.106.153.149" atau api.thingspeak.com
  {
    String postStr = apiKey;
    postStr += "&field1="; // field 1 pada thinkspeak
    postStr += String(h / 1023 * 100);
    postStr += "r\n";
    
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    Serial.print("Gas Level: ");
    Serial.println(h / 1023 * 100);
    Serial.println("Data Send to Thingspeak");
  }
  delay(500);
  client.stop();
  Serial.println("Waiting...");

  // delay 15 detik 
  delay(1500);
}
