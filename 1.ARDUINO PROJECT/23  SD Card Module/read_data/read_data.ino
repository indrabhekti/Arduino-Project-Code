
#include <SPI.h>
#include <SD.h>
File myFile; 
 
void setup() 
{ // Buka KomunikasiSerial 
 Serial.begin(9600); 
 
Serial.println("Open file on MicroSD card...");
 
  if (!SD.begin(4)) {
    Serial.println("Failed read open Microsd card!");
    return;
  }
 
 // Buka File 
 myFile = SD.open("dlog.txt"); 
 
 if (myFile)
 { Serial.println("dlog.txt");
 
 while(myFile.available())   // tunggu sampai file siap terbuka 
 { 
 Serial.write(myFile.read()); 
 }
 
 // menampilkan data ke serial monitor 
 Serial.println("berhasil ditampilkan"); 
myFile.close();
    Serial.println("done!"); 
  } else {
    // jika gagal print error
    Serial.println("failed open cobabaca.txt");
  }
} 
 
void loop() 
 { 
 }
