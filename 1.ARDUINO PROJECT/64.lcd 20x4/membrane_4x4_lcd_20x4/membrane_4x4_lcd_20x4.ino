
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


const byte numRows= 4; //baris pada keypad
const byte numCols= 4; //Kolom pada keypad

/*keymap mendefinisikan tombol ditekan sesuai
dengan baris dan kolom seperti muncul pada keypad*/
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};


byte rowPins[numRows]= {9,8,7,6}; 
byte colPins[numCols]= {5,4,3,2}; 


Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

LiquidCrystal_I2C lcd(0x27,20,4); // set the LCD address to 0x27 for a 16 chars and 2 line

void setup()
{
Serial.begin(9600);
 lcd.init(); 
 lcd.backlight();
}

// Jika tombol ditekan, tombol ini disimpan dalam 'keypressed' variabel
// Jika kunci tidak sama dengan 'NO_KEY', maka tombol ini dicetak
// Jika jumlah = 17, maka penghitungan reset kembali ke 0 (ini berarti tidak ada tombol yang ditekan selama proses pemindaian seluruh keypad

void loop()
{
char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY)
{
Serial.print(keypressed);
 lcd.setCursor(0,0);
 lcd.print(keypressed);
}
}
