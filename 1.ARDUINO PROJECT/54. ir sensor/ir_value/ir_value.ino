int analogInPin = A0;  // Analog input 
 
int out =13;
int sensorValue = 0;        // value read
 
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(out, OUTPUT);
}
 
void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
 
  Serial.print("sensor = " );
  Serial.println(sensorValue);
 
  delay(200);
  
  if(sensorValue>800)
  {
    digitalWrite(out,1);
  }
  else
  {
    digitalWrite(out,0);
  }
}
