 #include <LiquidCrystal.h> // library
// inisialisai dari library untuk menentukan pinout lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorReading = 0; //ldr pada A0

void setup()
{
  pinMode(A0, INPUT); //sebagai input
  Serial.begin(9600);

  pinMode(9, OUTPUT);// Buzzer pada pin 6 output
  lcd.begin(16, 2); //INISISLIASAI LCD
  
}

void loop()
{
  
  sensorReading = analogRead(A0); //defisnis dari pembacaan A0
 
  Serial.println(sensorReading);
   lcd.setCursor(0, 1);
  lcd.print(sensorReading);
  delay (1000);
  
  tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
  delay(10); 
}
