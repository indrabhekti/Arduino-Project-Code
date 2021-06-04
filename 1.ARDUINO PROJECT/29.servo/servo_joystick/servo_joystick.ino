#include <Servo.h>

const int X_pin = A0; 
const int Y_pin = A1;
 const int led = 13;                //led hijau pada pin 13
const int tombol = 2;                 //tombol pada pin 2


int buttonState = 0;
Servo myservo;  
int val;  


void setup() {
  myservo.attach(9); 
    Serial.begin (9600);
  pinMode (tombol, INPUT);
  pinMode (led, OUTPUT);
  digitalWrite (tombol, HIGH);
   digitalWrite (led, LOW);
}
void loop() {
  val = analogRead(Y_pin);            
  val = map(val, 0, 1023, 0, 180);  
  myservo.write(val);       
  delay(15); 

    buttonState = digitalRead (tombol);
  Serial.println (buttonState);

  if (buttonState == HIGH){
  digitalWrite (led, LOW);
  }

  else {
    if (buttonState == LOW)
    digitalWrite (led,HIGH );
    

}
}
