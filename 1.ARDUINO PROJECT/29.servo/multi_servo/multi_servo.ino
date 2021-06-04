#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial SerialBT (10, 11);
String data;
Servo servo1, servo2, servo3;
int val1 = 0, val2 = 0, val3 = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(7);
  Serial.begin(9600);
  SerialBT.begin(9600);
  servo1.write(0);
}

void loop() {

  
  // put your main code here, to run repeatedly:
  while (SerialBT.available() > 0) {
    delay(10);
    char c = SerialBT.read();
    data += c;
  }
  if (data.length() > 0) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(data);
    Serial.println(data);
    // Test if parsing succeeds.
    if (!root.success()) {
      Serial.println("parseObject() failed");
      return;
    }

    val1 = root["val1"];
    val2 = root["val2"];
    val3 = root["val3"];

    servo1.write(val1);
    servo2.write(val2);
    servo3.write(val3);
    
    Serial.print(val1);
    Serial.print("\t");
    Serial.print(val2);
    Serial.print("\t");
    Serial.print(val3);
    Serial.print("\n");
    data = "";
  }

}
