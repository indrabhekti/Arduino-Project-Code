#include <SPI.h>
#include <SD.h>
#include <Servo.h>

// CS pin for SD Card Module
const int chipSelect = 4;
// Analog pin for potentiometer
int analogPin = 0;
// Integer to hold potentiometer value
int val = 0;

// Create a Servo object
Servo myservo;

void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");

  // Attach servo on pin 9 to the servo object
  myservo.attach(9);
}

void loop() {
  // make a string for assembling the data to log:
  String dataString = "";

  // Read pot value and append to the string
  // Map to range of 0-180 for servo
  val = map(analogRead(analogPin), 0, 1023, 0, 180);
  dataString += String(val);

  // Write to the servo
  // Delay to allow servo to settle in position
  myservo.write(val);
  delay(15);


  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("servopos.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening servopos.txt");
  }
}
