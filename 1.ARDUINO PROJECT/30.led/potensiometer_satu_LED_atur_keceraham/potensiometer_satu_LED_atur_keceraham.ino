
const int analogInPin = A0;  // potensiometer taruh di A0
const int analogOutPin =3; //pin led

int sensorValue = 0;        // value read dari pot
int outputValue = 0;        // value output ke PWM (analog out)

void setup() {
  
  Serial.begin(9600);
}

void loop() {
 
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
 
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // 2 milliseconds sebelum next loop untuk dari analog-ke-digital
 
  delay(2);
}
