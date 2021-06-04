

#define pinecho1 2
#define pinecho2 3
#define pinecho3 4

#define pintriger1 5
#define pintriger2 6
#define pintriger3 7

float read_srf(int pintriger, int pinecho) {
  long durasi;
  float jarak;
  digitalWrite(pintriger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintriger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pintriger, LOW);
  delayMicroseconds(2);

  durasi = pulseIn(pinecho, HIGH);
  jarak = durasi / 58.2;

  return jarak;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 5; i <= 6; i++) {
    pinMode (OUTPUT, i);
  }

  for (int i = 2; i <= 4; i++) {
    pinMode (INPUT, i);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Sensor Jarak1 : ");
Serial.print(read_srf(pintriger1, pinecho1));
Serial.print("\tSensor Jarak1 : ");
Serial.print(read_srf(pintriger2, pinecho2));
Serial.print("\tSensor Jarak1 : ");
Serial.print(read_srf(pintriger3, pinecho3));
Serial.println();
}
