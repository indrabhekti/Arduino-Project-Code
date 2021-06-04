#include<SPI.h>
#include<SD.h>
#include<MFRC522.h>
#include<DS3231.h>
#include<LiquidCrystal.h>

DS3231 rtc(SDA,SCL);
LiquidCrystal lcd(7,6,5,3,2,A0);

const int rst=9;
const int ss=10;
const int relay=8;
const int cs=4;
bool on=LOW;
bool off=HIGH;
String hari;
String jam;
String tanggal;
String id;

MFRC522 rfid(ss, rst);
File file;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  pinMode(relay,OUTPUT);
  lcd.begin(16,2);
  while(!Serial){
    ;
  }
  SPI.begin();
  digitalWrite(relay,off);
  delay(100);
  rfid.PCD_Init();
  Serial.println("System Siap!!");
  lcd.setCursor(5,0);
  lcd.print("Selamat");
  lcd.setCursor(6,1);
  lcd.print("Datang");
  delay(2000);
}

void loop() {
  cekRfid();
  delay(100);
}

void cekRfid(){
  if(rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
    Serial.println("ID: ");
    for(int i=0; i<=3; i++){
      id=id+(rfid.uid.uidByte[i]<0x10 ? "0" : "") + String(rfid.uid.uidByte[i],HEX) + (i==3 ? "" : ":");
    }
    id.toUpperCase();
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    tampilkan();
    inputData();
  }
}

void tampilkan(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ID ");
  lcd.setCursor(5,0);
  lcd.print(id);
  jam=rtc.getTimeStr();
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Jam");
  lcd.setCursor(5,1);
  lcd.print(jam);
}

void inputData(){
  hari=rtc.getDOWStr();
  jam=rtc.getTimeStr();
  tanggal=rtc.getDateStr();
  digitalWrite(relay,on);
  SD.begin(cs);
  file=SD.open("hadir.txt", FILE_WRITE);
  if(file){
    file.print(id);
    file.print(",");
    file.print(hari);
    file.print(",");
    file.print(tanggal);
    file.print(",");
    file.println(jam);
    Serial.println(id);
    Serial.println("Data berhasil ditambahkan!!");
    file.close();
  }else{
    Serial.println("Data error, gagal menyimpan!!");
  }
  id="";
  digitalWrite(relay,off);
}

