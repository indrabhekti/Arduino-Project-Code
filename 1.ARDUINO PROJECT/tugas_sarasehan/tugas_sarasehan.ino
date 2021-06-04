
//tugas project alat
//tombol penyebrang jalan
//10/12/2019
//by dafawijaya


const int ledmerah = 12;                  //led merah pada pin 12 penyebrang
const int ledhijau = 13;                //led hijau pada pin 13
const int merah = 11;                  //led merah pada pin 11 mobil
const int hijau = 10;                //led hijau pada pin 10 
const int tombol = 2;                 //tombol pada pin 2
 int buzzer = 7;               //buzzer pada pin 8

int buttonState = 0; //untuk me memori tombol jika ditekan atau tidak

void setup() {
  Serial.begin(9600);
  pinMode (ledmerah , OUTPUT); //sebagai output
  pinMode (ledhijau, OUTPUT);   //sebagai output
  pinMode (merah , OUTPUT); //sebagai output
  pinMode (hijau, OUTPUT);   //sebagai output
  pinMode (tombol, INPUT);       //sebagai input
  pinMode (buzzer, OUTPUT);       //sebagai output
  digitalWrite (tombol, HIGH);
}

void loop() {

  buttonState = digitalRead (tombol);
  Serial.println (buttonState);

  if ( buttonState == LOW) {      //jika tombol ditekan maka:
    digitalWrite (ledmerah, LOW) ;  //led merah mati
    digitalWrite (ledhijau, HIGH);   //led hijau menyala

    digitalWrite (merah, HIGH) ;  //led merah mati
    digitalWrite (hijau, LOW);   //led hijau menyala
                 


    if (ledhijau, HIGH)             // jika led hijau menyala buzzer berbunyi
    {
   
      tone(7, 2900, 200);         // buzzer (pada pin 7) berbunyi dengan 2900 Hz selama 200 ms
      delay(300);                //delay selama 300 ms
        tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300);
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
       tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
         tone(7, 2900, 200);
        delay(300); 
    
      digitalWrite(ledhijau, LOW);   //mematikan led hijau
      digitalWrite(ledmerah, HIGH); //menyalakan led merah
    }
  }


  else {                               //jika tombol tidak di tekan, maka:         
    digitalWrite (ledmerah, HIGH);   //led merah menyala PENYEBRAMH
    digitalWrite (ledhijau, LOW);  //led hijau mati

     digitalWrite (merah, LOW);   //led merah menyala MOBIL
    digitalWrite (hijau, HIGH);  //led hijau mati
  }


}
