//receiver

#include <SPI.h> //penyertaan library header penggunaan interface SPI
#include <nRF24L01.h> //penyertaan library header nRF24L01
#include <RF24.h> //penyertaan library header RF24

int pesan[1];
RF24 radio(9, 10); //pin yang dideklarasikan untuk chip enable, chip selector
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED = 7; //nama alias untuk pin.2 yaitu LED

void setup(void) {
  Serial.begin(9600); //menggunakan serial monitor pada 9600bps
  radio.begin(); //instruksi prosedur mulai pembacaan module
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  pinMode(LED, OUTPUT);
} //deklarasi pin sebagai output

void loop(void) {
  if (radio.available()) { //jika terbaca data di module
    bool selesai = false;
    while (!selesai) { //perulangan apabila selesai = TRUE
      selesai = radio.read(pesan, 1);
      Serial.println(pesan[0]); //menuliskan informasi di serial monitor
      if (pesan[0] == 111) {
        delay(10);  //jika sesuai data, maka RELAY akan menyala
        digitalWrite(LED, HIGH);
      }
      else {
        digitalWrite(LED, LOW);
      }
      delay(10);
    }
  } //nilai tunda 10 ms untuk pembacaan data berikutnya
  else {
    Serial.println("RELAY MENYALA");
  }
}
