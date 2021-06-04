//dafa wijaya
//no pin pada arduino
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // trigPin jadi  Output
pinMode(echoPin, INPUT); // echoPin jadi Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Serial komunikasi
}


void loop() {
//
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// 
duration = pulseIn(echoPin, HIGH);

// kalkulasi
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 60){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
Serial.print("Distance: ");
Serial.println(distance);
}
