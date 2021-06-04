const int led = 13;                //led hijau pada pin 13
const int tombol = 2;                 //tombol pada pin 2


int buttonState = 0; //untuk me memori tombol jika ditekan atau tidak


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (tombol, INPUT);
  pinMode (led, OUTPUT);
  digitalWrite (tombol, HIGH);
   digitalWrite (led, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead (tombol);
  Serial.println (buttonState);

  if (buttonState == HIGH){
  digitalWrite (led, HIGH);
  }

  else {
    if (buttonState == LOW)
    digitalWrite (led, LOW);
    

}
}
