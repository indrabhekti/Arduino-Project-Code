/*AT-MO PRODUCTION
RFID ektp
tolong jika menggunakan code ini
mohon masukan sumber seperti di bawah ini

"AT-MO PRODUCTION 
di BUAT BY OGI SINATRA"
*/
#include <RFID.h>
#include <SPI.h>

#define SS_PIN 10// sda pin rfid
#define RST_PIN 9

const int merah = 3; // pin led 
const int hijau = 2;

RFID rfid(SS_PIN,RST_PIN);

int serNum[5];

int card1[][5] =
{
  {}// isi alamat card
};

int card2[][5] =
{
  {}// isi alamat card 
};

int card3[][5] =
{
  {}// isi alamat card
};

bool access = false;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();

  pinMode(merah, OUTPUT);
  pinMode(hijau, OUTPUT);

  digitalWrite(merah, LOW);
  digitalWrite(hijau, LOW);
}

void loop()
{

if(rfid.isCard())
  {
  if(rfid.readCardSerial())
  {
    Serial.print(rfid.serNum[0]);
    Serial.print(" ");
    Serial.print(rfid.serNum[1]);
    Serial.print(" ");
    Serial.print(rfid.serNum[2]);
    Serial.print(" ");
    Serial.print(rfid.serNum[3]);
    Serial.print(" ");
    Serial.print(rfid.serNum[4]);
    Serial.print(" ");

//--------------------card 1----------------------
      for(int x =0; x< sizeof (card1); x++) // awal code check card 1
      {
        for(int i = 0; i<sizeof(rfid.serNum); i++)
        {
          if(rfid.serNum[i] != card1 [x] [i])
          {
            access = false;
            break;
          }
          else{
            access = true;
          }
        }
      if(access) break;
      } // untuk card satu

//---------------------card 2---------------------------
      for(int x =0; x< sizeof (card2); x++) // awal code check card 2
      {
        for(int i = 0; i<sizeof(rfid.serNum); i++)
        {
          if(rfid.serNum[i] != card2 [x] [i])
          {
            access = false;
            break;
          }
          else{
            access = true;
          }
        }
      if(access) break;
      } // untuk card 2

//----------------------card 3----------------------------
     for(int x =0; x< sizeof (card3); x++) // awal code check card 3
      {
        for(int i = 0; i<sizeof(rfid.serNum); i++)
        {
          if(rfid.serNum[i] != card3 [x] [i])
          {
            access = false;
            break;
          }
          else{
            access = true;
          }
        }
      if(access) break;
      } // untuk card 3
//--------------------------------------------------------------     
  }

if (access) 
{
  Serial.println("BERHASIL");
  digitalWrite(hijau, HIGH);
  delay(2000);
  digitalWrite(hijau, LOW);
}

else 
{
  Serial.println("card tidak terdaftar");
  digitalWrite(merah, HIGH);
  delay(500);
  digitalWrite(merah, LOW);
  delay(500);
  digitalWrite(merah, HIGH);
  delay(500);
  digitalWrite(merah, LOW);
}
}
  rfid.halt();
}
