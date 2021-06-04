#include <Servo.h>

Servo myservo;
int Button1 = 4;
int Button2 = 5;
int Button3 = 6;
int led1 = 13;
int led2 = 12;
int led3 = 11;

int pos = 0; // a variable to store the servo position
int delayPeriod = 2;  // increasing this slows down the servo movement



void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos); // center the servo
  pinMode(Button1 , INPUT_PULLUP);   // turn on pullup resistors
  pinMode(Button2 , INPUT_PULLUP);
  pinMode(Button3 , INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}



void loop()
{
  if (digitalRead(Button1) == LOW)
  {

    myservo.write(0);
    delay(delayPeriod);
    digitalWrite (led1, HIGH);
  }

  if (digitalRead(Button2) == LOW)
  {

    myservo.write(90);              // tell servo to go to position in variable 'pos'
    delay(delayPeriod);
    digitalWrite (led2, HIGH);
  }
  if (digitalRead(Button3) == LOW)
  {

    myservo.write(180);              // tell servo to go to position in variable 'pos'
    delay(delayPeriod);
    digitalWrite (led3, HIGH);
  }

}
