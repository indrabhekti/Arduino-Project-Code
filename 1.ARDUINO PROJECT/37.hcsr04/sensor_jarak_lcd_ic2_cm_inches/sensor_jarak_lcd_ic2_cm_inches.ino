#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LcdBarGraphRobojax.h>


byte lcdNumCols = 16; // -- number of columns in the LCD
byte lcdLine = 2; // -- number of line in the LCD

LiquidCrystal_I2C lcd(0x27,lcdNumCols,lcdLine); // is address for I2C
                  // to get I2C address, run I2C Scanner. 
                  //Link is provided (in same page as this code) at http://robojax.com/learn/arduino
LcdBarGraphRobojax lbg(&lcd, 16, 0, 0);  // -- creating 16 character long bargraph starting at char 0 of line 0 (see video)

#include <NewPing.h>

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 30 // Maximum distance we want to ping for (in centimetres). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int VCC2 = 2;// additional VCC(5) for device
void setup(){
  pinMode(VCC2, OUTPUT);// extra VCC for ultrasonic
  digitalWrite(VCC2, HIGH);//extra VCC is now HIGH (5V)
    
  // -- initializing the LCD
  
  lcd.clear();
  lcd.print("Robojax"); 
  lcd.setCursor (0,1); //  
  lcd.print("Bargraph"); 
   
  // -- do some delay: some time I've got broken visualization
  delay(2000);
  lcd.clear();
}

void loop()
{
  int distanceCM = sonar.ping_cm();// get distance in cm
  int distanceIN = sonar.ping_in();// get distance in in
 


  // -- draw bar graph from the analog value 

  // -- do some delay: frequent draw may cause broken visualization
 
  lcd.setCursor (0,1); //
  lcd.print("Distance:"); 
  lcd.setCursor (10,1); //
  lcd.print(distanceCM); // print
  lcd.setCursor (14,1); //  
  lcd.print("cm");   
 
  delay(100);
}
 
