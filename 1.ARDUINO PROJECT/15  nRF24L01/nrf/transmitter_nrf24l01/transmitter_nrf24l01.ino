// transmitter
//

#include <SPI.h> //penyertaan library header penggunaan interface SPI
#include <nRF24L01.h> //penyertaan library header nRF24L01
#include <RF24.h> //penyertaan library header RF24
int pesan[1];
RF24 radio(9, 10); //instruksi untuk chip enable, dan chip selector
const uint64_t pipe = 0xE8E8F0F0E1LL;
int pushbutton = 2; //nama alias pin.2 dengan nama pushbutton

void setup(void) {
  Serial.begin(9600); //penggunaan serial monitor dengan kecepatan 9600bps
  radio.begin(); //instruksi memulai prosedur pembacaan module
  radio.openWritingPipe(pipe);
  pinMode(pushbutton, INPUT);
} //deklarasi pushbutton sebagai input

void loop(void) {
  if (digitalRead(pushbutton) == HIGH) { //jika pushbutton ditekan
    pesan[0] = 111;
    radio.write(pesan, 1);
  }
} //mengirim data
