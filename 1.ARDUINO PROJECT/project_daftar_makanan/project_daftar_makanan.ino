#include <LiquidCrystal_I2C.h>

#include <Keypad.h>
 
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {8, 9, 10, 11};
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
 
struct daftarMenu {
  char strMenu[17];
  uint32_t harga;
  bool pilihan;
};
 
char menuUtama[][17] = {
  "0..9 - Pilih    ",
  "* - Pilih       ",
  "# - Batal       ",
  "A - Makanan     ",
  "B - Minuman     ",
  "C - Total/Pesan ",
  "D - Batal       ",
};
daftarMenu menuMakanan[] = {
  {"1 Nasi Goreng   ", 13000L, false},
  {"2 Mie Goreng    ", 8000L, false},
  {"3 Bihun Goreng  ", 8000L, false},
  {"4 Mie Rebus     ", 6000L, false},
  {"5 Gado-gado     ", 13000L, false},
  {"6 Soto Padang   ", 15000L, false},
  {"7 Sate Padang   ", 18000L, false},
};
daftarMenu menuMinuman[] = {
  {"1 Es Campur     ", 6000L, false},
  {"2 Es Tebak      ", 7500L, false},
  {"3 Es Kosong     ", 2000L, false},
  {"4 Jus Jeruk     ", 6000L, false},
  {"5 Jus Pokat     ", 6500L, false},
  {"6 Kopi          ", 4000L, false},
  {"7 Teh Panas     ", 4000L, false},
  {"8 Teh Telur     ", 8000L, false},
};
 
int8_t indexMenu = -1;
byte menuLevel = 0;
byte menuLevelSebelumnya = -1;
 
enum ModeMenu {
  modeMenuMakanan,
  modeMenuMinuman,
};
ModeMenu modeMenu;
#define standarWaktuTampil  1000L
#define LihatWaktuTampil    5000L
#define jumlahMakanan       sizeof(menuMakanan)/sizeof(menuMakanan[0])
#define jumlahMinuman       sizeof(menuMinuman)/sizeof(menuMinuman[0])
 
uint16_t waktuTampil;
unsigned long millisMulai;
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Menu LCD Arduino dengan keypad");
  Serial.println("http://www.semesin.com/project/");
 
  Wire.begin();
  Wire.beginTransmission(0x3F);
  if (Wire.endTransmission())
  {
    lcd = LiquidCrystal_I2C(0x27, 16, 2);
  }
lcd.init();
  lcd.backlight();
  //  tampilanDepan();
  millisMulai = millis();
  resetPilihan();
}
 
void loop()
{
  char key = keypad.getKey();
 
  if (key) {
    Serial.println(key);
    switch (key)
    {
      case 'A':
        menuLevel = 1;
        indexMenu = -1;
        modeMenu = modeMenuMakanan;
        break;
      case 'B':
        menuLevel = 1;
        indexMenu = -1;
        modeMenu = modeMenuMinuman;
        break;
      case 'C':
        menuLevel = 2;
        updateMenu();
        break;
      case 'D':
        resetPilihan();
        menuLevel = 0;
        indexMenu = -1;
        updateMenu();
        break;
      case '*':
        if (menuLevel == 2)
        {
          pesananMasuk();
        }
        else
        {
          if (waktuTampil == LihatWaktuTampil)
          {
            if (modeMenu == modeMenuMakanan)
            {
              menuMakanan[indexMenu].pilihan = true;
            }
            else if (modeMenu == modeMenuMinuman)
            {
              menuMinuman[indexMenu].pilihan = true;
            }
            updateMenu();
          }
          else
          {
            waktuTampil = LihatWaktuTampil;
            millisMulai = millis();
          }
        }
        break;
      case '#':
        if (menuLevel == 2)
        {
          menuLevel = 1;
        }
        else
        {
          if (waktuTampil == LihatWaktuTampil)
          {
            if (modeMenu == modeMenuMakanan)
            {
              menuMakanan[indexMenu].pilihan = false;
            }
            else if (modeMenu == modeMenuMinuman)
            {
              menuMinuman[indexMenu].pilihan = false;
            }
            updateMenu();
          }
          else
          {
            waktuTampil = LihatWaktuTampil;
            millisMulai = millis();
          }
        }
        break;
      default:
        indexMenu = key - '1';
        updateMenu();
        millisMulai = millis();
        waktuTampil = LihatWaktuTampil;
        break;
    }
  }
 
  if (millis() - millisMulai > waktuTampil)
  {
    millisMulai = millis();
    waktuTampil = standarWaktuTampil;
    indexMenu++;
    updateMenu();
    menuLevelSebelumnya = menuLevel;
  }
}
void pesananMasuk()
{
  //Aksi pesanan masuk
  lcd.setCursor(0, 0);
  lcd.println("  Terima Kasih  ");
  lcd.setCursor(0, 1);
  lcd.println("Silahkan tunggu ");
  delay(3000);
  Serial.println("Pesanan masuk!!!");
  menuLevel = 0;
  indexMenu = -1;
}
void updateMenu()
{
  if (menuLevel == 0)
  {
    if (indexMenu == sizeof(menuUtama) / sizeof(menuUtama[0]))
    {
      indexMenu = 0;
    }
    if (menuLevelSebelumnya != menuLevel)
    {
      lcd.clear();
      lcd.print("Selamat Datang");
    }
    tampilMenuUtama(indexMenu);
  }
  else if (menuLevel == 2)
  {
    lcd.setCursor(0, 0);
    lcd.print("Rp. ");
    formatStrHarga(totalPilihan());
    lcd.setCursor(0, 1);
    lcd.print("* Ya   # kembali");
  }
  else if (modeMenu == modeMenuMakanan)
  {
    if (indexMenu >= jumlahMakanan)
    {
      indexMenu = 0;
    }
    tampilMenuMakanan(indexMenu);
  }
  else if (modeMenu == modeMenuMinuman)
  {
    if (indexMenu >= jumlahMinuman)
    {
      indexMenu = 0;
    }
    tampilMenuMinuman(indexMenu);
  }
}
void resetPilihan()
{
  for (byte i = 0; i < jumlahMakanan; i++)
  {
    menuMakanan[i].pilihan = false;
  }
  for (byte i = 0; i < jumlahMinuman; i++)
  {
    menuMinuman[i].pilihan = false;
  }
}
uint32_t totalPilihan()
{
  uint32_t total = 0;
  for (byte i = 0; i < jumlahMakanan; i++)
  {
    if (menuMakanan[i].pilihan)
    {
      total += menuMakanan[i].harga;
    }
  }
  for (byte i = 0; i < jumlahMinuman; i++)
  {
    if (menuMinuman[i].pilihan)
    {
      total += menuMinuman[i].harga;
    }
  }
  return total;
}
void tampilMenuUtama(byte index)
{
  lcd.setCursor(0, 1);
  lcd.print(menuUtama[index]);
}
void tampilMenuMakanan(byte index)
{
  lcd.setCursor(0, 0);
  lcd.print(menuMakanan[index].strMenu);
  lcd.setCursor(0, 1);
  lcd.print("Rp. ");
  formatStrHarga(menuMakanan[index].harga);
  if (menuMakanan[index].pilihan)
  {
    lcd.setCursor(15, 1);
    lcd.print("*");
  }
}
void tampilMenuMinuman(byte index)
{
  lcd.setCursor(0, 0);
  lcd.print(menuMinuman[index].strMenu);
  lcd.setCursor(0, 1);
  lcd.print("Rp. ");
  formatStrHarga(menuMinuman[index].harga);
  if (menuMinuman[index].pilihan)
  {
    lcd.setCursor(15, 1);
    lcd.print("*");
  }
}
void formatStrHarga(uint32_t harga)
{
  String strHarga = String(harga);
  uint8_t panjangStr = strHarga.length();
  uint8_t offset = 3 - (panjangStr % 3);
  for (byte i = 0; i < strHarga.length(); i++)
  {
    lcd.print(strHarga[i]);
    if (!((strHarga.length() + i - offset + 1) % 3))
    {
      if (i != strHarga.length() - 1)
      {
        lcd.print('.');
      }
    }
  }
  for (byte i = 0; i < 16 - 5 - strHarga.length(); i++)
  {
    lcd.print(' ');
  }
}
