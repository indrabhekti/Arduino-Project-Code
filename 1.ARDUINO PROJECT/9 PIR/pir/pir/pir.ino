int calibrationTime = 30;       //waktu untuk kalibrasi
 
//waktu ketika sensor outputs pada low impulse
long unsigned int lowIn;        
 
//5000 milliseconds sensor harus low
//sebelum kita beranggapan bahwa gerakan berhenti
long unsigned int pause = 5000; 
 
boolean lockLow = true; // untuk void loop
boolean takeLowTime; 
 
int pirPin = 3;    //pir output pada pin D3 

 
 
void setup(){
  Serial.begin(9600); //serial komunikasi
  pinMode(pirPin, INPUT); //pir sebagai input 
  digitalWrite(pirPin, LOW); //pir pin pada kondisi low
 
  //beri waktu sensor untuk kalibrasi
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50); //delay sebsor
  }
 

void loop(){
 
     if(digitalRead(pirPin) == HIGH){ //jika pir mendeteksi ada nya gerakan
      

       //dan akan mnampilkan bahwa gerakan terdetaksi 
       if(lockLow){ 
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;

 
       }
       
 
     if(digitalRead(pirPin) == LOW){  //jika pir mendetaksi tidak ada gerakan
    

       //dan akan menampilkan bahwa gerakan telah berakhir
       
 
       if(takeLowTime){
        lowIn = millis();          
        takeLowTime = false;       
        }

       if(!lockLow && millis() - lowIn > pause){ 
          
           lockLow = true;                       
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
  }
