#include <Adafruit_Fingerprint.h>

const int relay = 8; //relay di pin d8
const int led_pin_deny = 9;
volatile int finger_status = -1;

SoftwareSerial mySerial(2, 3); // TX/RX . pin d2 ke rx fingerprint pin d3 ke tx fingerprint

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(led_pin_deny,OUTPUT);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

void loop()                     // run over and over again
{
  finger_status = getFingerprintIDez();
  if (finger_status!=-1 and finger_status!=-2){
    digitalWrite(relay,HIGH);
    delay(5000);
  } else{
    if (finger_status==-2){
      for (int ii=0;ii<5;ii++){
        digitalWrite(led_pin_deny,HIGH);
        delay(50);
        digitalWrite(led_pin_deny,LOW);
        delay(50);
      }
    }
    digitalWrite(relay,LOW);
  }
  delay(50);            //don't ned to run this at full speed.
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p!=2){
    Serial.println(p);
  }
  if (p != FINGERPRINT_OK)  return -1;
  
  p = finger.image2Tz();
  if (p!=2){
    Serial.println(p);
  }
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -2;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
