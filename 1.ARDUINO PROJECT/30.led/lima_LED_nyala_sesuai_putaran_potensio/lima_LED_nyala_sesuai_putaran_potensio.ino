int pin1 = 2;//membuat variabel pin1 = pin 2 pada arduino
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6;
int analog = A0;
void setup() {
  pinMode(pin1, OUTPUT); //menge-set pin yang sudah dideklarasi sebagai output tegangan
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(analog, INPUT);//menjadikan pin A0 sebagai INPUT tegangan
  Serial.begin(9600);    //code untuk mencetak pada serial monitor
}

void loop() {
  int baca = analogRead(analog) / 4; //membuat variabel baru untuk mebaca tegangan yg ada pada pin A0 dan dibagi 4,kenapa dibagi 4?untuk lebih mempermudah hitungan saja
  Serial.println(baca);              //mencetak hasil pembacaan tegangan yg telah dibagi 4 pada variabel baca dan di cetak di serial monitor

  //membuat kondisi untuk menjadwalkan led menyala pada saat potensiometer diputar hingga tegangan yg telah di tentukan
  if (baca > 0) {              //jika potensiomter tegangannya lebih dari 0 maka
    digitalWrite(pin1, HIGH);  //led 1 menyala
  } else {                     //jika potensio kurang dari 0 maka
    digitalWrite(pin1, LOW);   //led 1 mati
  }

  if (baca > 55) {             //jika potensiomter tegangannya lebih dari 55 maka
    digitalWrite(pin2, HIGH);  //led 2 menyala
  } else {                     //jika potensio kurang dari 55 maka
    digitalWrite(pin2, LOW);   //led 2 mati
  }

  if (baca > 110) {            //jika potensiomter tegangannya lebih dari 110 maka
    digitalWrite(pin3, HIGH);  //led 3 menyala
  } else {                     //jika potensio kurang dari 110 maka
    digitalWrite(pin3, LOW);   //led 3 mati dst.
  }

  if (baca > 155) {
    digitalWrite(pin4, HIGH);
  } else {
    digitalWrite(pin4, LOW);
  }

  if (baca > 220) {
    digitalWrite(pin5, HIGH);
  } else {
    digitalWrite(pin5, LOW);
  }

}
