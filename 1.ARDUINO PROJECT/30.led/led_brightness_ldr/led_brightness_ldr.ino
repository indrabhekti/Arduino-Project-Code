int sensor = A0;
int lightvalue = 0;
int val = 0;
int led = 10;

int ldrlevel1 = 0;
int ldrlevel2 = 50;
int ldrlevel3 = 150;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);

}

void loop() {
  lightvalue = analogRead(sensor);
  //for this LDR , high value is 679 and low is 6
  
  Serial.println(lightvalue);
  val = lightvalue;
  //val = lightvalue/2.7;
  //val = 255-val;
  //Serial.println(val);
  if (val > ldrlevel1) {
    Serial.println("dark");
    analogWrite(led, val);
    delay (1000);
  }
  if (val >ldrlevel2) {
    Serial.println("light");
    analogWrite(led, val);
    delay (1000);
  }
  if (val > ldrlevel3) {
    Serial.println("bright");
    analogWrite(led, val);
    delay (1000);
  }
}
