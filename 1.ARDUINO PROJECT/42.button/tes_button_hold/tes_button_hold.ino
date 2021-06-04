
bool flag, state;
const int btnPin = 2;
const int ledPin = 3;


void setup() {
  // put your setup code here, to run once:
pinMode(btnPin, INPUT_PULLUP);
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(!digitalRead(btnPin)){
if(!flag){
flag = true;
state = !state;
digitalWrite(ledPin, state);
}
} else {
flag = false;
}
}
