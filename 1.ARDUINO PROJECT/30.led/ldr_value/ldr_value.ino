int photocellPin = 0; // LDR and 10K pulldown registor are connected to A0
int photocellReading; // Variable to read the analog value

int val = 0;
int led = 10;
void setup(void) {
 // Initialize Serial Monitor
 Serial.begin(9600); 
  pinMode(photocellPin, INPUT);
}
 
void loop(void) {
 photocellReading = analogRead(photocellPin);

  photocellReading = map( photocellReading, 6, 679, 255, 0);
 
  val =  photocellReading;

if (photocellReading <= 200) {
 Serial.println("DARK : Analog Value = " + String(photocellReading)); 
  analogWrite(led, val);
 }
 else if (photocellReading > 200 && photocellReading <= 500) {
 Serial.println("LIGHT : Analog Value = " + String(photocellReading)); 
  analogWrite(led, val);
 } 
 else if (photocellReading > 500 && photocellReading <= 800) {
 Serial.println("BRIGHT  : Analog Value = " + String(photocellReading)); 
  analogWrite(led, val);
 } 

 
 delay(100);
}
