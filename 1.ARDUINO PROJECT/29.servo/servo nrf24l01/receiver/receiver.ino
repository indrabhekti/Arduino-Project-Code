        
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo servo;
RF24 radio(7, 8); // CSN, CE
const byte address[6] = "00001";
int servo_pin = 6;

void setup() {
  Serial.begin(9600);
  radio.begin();
  servo.attach (servo_pin ) ; 
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int x_pos ;
    radio.read(&x_pos, sizeof(x_pos));
    Serial.println(x_pos);
    x_pos = map(x_pos, 0, 1023, 0, 180);
    if (x_pos>400 && x_pos<600)
    {
      
    }
    else{
    servo.write (x_pos) ;
    }
  }
}

    
