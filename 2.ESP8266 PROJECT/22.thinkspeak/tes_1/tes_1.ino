


#include <ESP8266WiFi.h>  
#include <ESPDailyTask.h> //library yang dimasukan di program file (x86)/arduino/libraries
#include "DHT.h"

//sensor yang digunakan
#define DHTTYPE DHT11   // DHT 11

const char* ssid     = "Kelg_Hadie";
const char* password = "Vitri1972";

//Copy paste API KEYS yang write
const char* apiKey = "P955FGEYN7JHPVDW";

const char* resource = "/update?api_key=";

// Thing Speak API server 
const char* server = "api.thingspeak.com";

// Set waktu kapan harus mengirimkan data 
ESPDailyTask dailyTask(7*60 + 15); // 7:15am

// DHT Sensor pada pin 5 di NodeMCU
const int DHTPin = 5;
//inisialisasi library DHTpin
DHT dht(DHTPin, DHTTYPE);

// Variabel temporary untuk suhu dan kelembaban
static char temperatureTemp[7];
static char humidityTemp[7];

void setup() {
  //Serial port untuk komunikasi serial
  Serial.begin(115200);
  delay(10);

  //mengirimkan data per hari hanya 1 kali, sesuai dengan waktu yang telah diset
  dailyTask.sleep1Day();
  
  //proses pembacaan sensor
  dht.begin();
  
  //fungsi untuk mengkoneksikan nodemcu ke wifi
  initWifi(); 
  
  //fungsi untuk komunikasi ke thingspeak 
  makeHTTPRequest();
  
  //untuk kembali ke mode sleep setelah mengirimkan data
  dailyTask.backToSleep();
}

void loop() {
}

//Koneksi nodemcu ke wifi
void initWifi() {
  Serial.print("Connecting to: "); 
  Serial.print(ssid);
  WiFi.begin(ssid, password);  

  int timeout = 10 * 4; // 10 detik
  
  while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if(WiFi.status() != WL_CONNECTED) {
     Serial.println("gagal terkoneksi, ke mode sleep");
  }

  Serial.print("Wifi sukses terkonek: "); 
  Serial.print(millis());
  Serial.print(", IP addr : "); 
  Serial.println(WiFi.localIP());
}

//membuat http request ke thingspeak
void makeHTTPRequest() {
  //pembacaan sensor
  float h = dht.readHumidity(); //untuk kelembaban
  float t = dht.readTemperature(); //untuk suhu dalam bentuk celcius
  float f = dht.readTemperature(true); //untuk suhu dalam bentuk fahrenheit
  
  //mengecek pembacaan sensor dht11
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Gagal pembacaan data DHT11!");
    strcpy(temperatureTemp,"GAGAL");
    strcpy(humidityTemp, "GAGAL");
    return;    
  }
 
  else {
    float hic = dht.computeHeatIndex(t, h, false);    
    dtostrf(hic, 6, 2, temperatureTemp);
                 
    float hif = dht.computeHeatIndex(f, h);
    //dtostrf(hif, 6, 2, temperatureTemp);   
          
    dtostrf(h, 6, 2, humidityTemp);
    Serial.print("Kelembaban: ");
    Serial.print(h);
    Serial.print(" %\t Suhu: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.print(" *F");
  }
  
  Serial.print("Connecting to "); 
  Serial.print(server);
  
  WiFiClient client;
  int retries = 5;
  while(!!!client.connect(server, 80) && (retries-- > 0)) {
    Serial.print(".");
  }
  Serial.println();
  if(!!!client.connected()) {
     Serial.println("gagal terkoneksi, ke mode sleep");
  }
  
  Serial.print("Permintaan sumber: "); 
  Serial.println(resource);
  //kunci dalam pengiriman data ke thingspeak
  client.print(String("GET ") + resource + apiKey + "&field1=" + temperatureTemp + "&field2=" + humidityTemp +
                  " HTTP/1.1\r\n" +
                  "Host: " + server + "\r\n" + 
                  "Connection: close\r\n\r\n");
                  
  int timeout = 5 * 10; // 5 seconds             
  while(!!!client.available() && (timeout-- > 0)){
    delay(100);
  }
  if(!!!client.available()) {
     Serial.println("Tidak ada response, going back to sleep");
  }
  while(client.available()){
    Serial.write(client.read());
  }
  
  Serial.println("\nclosing connection");
  client.stop();
}
