
#include <SPI.h>
#include <SD.h>
 
File myFile;
 
void setup() {
 Serial.begin(9600);   // baud komunikasi serial
 
  Serial.println("Buka file di kartu microSD");
 
  if (!SD.begin(4)) { //tergantung di pin chipselect yang digunakan
    Serial.println("Gagal baca microSD!");
    return;
  }
  Serial.println("Sukses baca kartu microSD!");
 
  myFile = SD.open("coba.txt", FILE_WRITE); //menulis File coba.txt
 
  // jika file sudah berhasil dibuka maka tulis data dimulai
  if (myFile) {
    Serial.println("mencoba nulis data di file coba.txt");
    myFile.println("success write data");
    // tutup file
    myFile.close();
    Serial.println("SELESAI!");
  } else {
    // jika gagal print error
    Serial.println("GAGAL TULIS coba.txt");
  }
}
 
void loop() {
}
 
