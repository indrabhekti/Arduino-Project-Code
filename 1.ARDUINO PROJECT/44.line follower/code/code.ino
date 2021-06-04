#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int left_sens_val;         //variable to store left IR sensor value
int right_sens_val;        //variable to store right IR sensor value

void setup() {

  motor1.setSpeed(150);   //motor speed range from 0-255
  motor2.setSpeed(150);


  motor1.run(RELEASE);    //motor stop
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void loop() {

  left_sens_val = analogRead(A2);     //left sensor connected to analog pin A0
  right_sens_val = analogRead(A3);    //right sensor connected to analog pin A1

  if (left_sens_val > 500 && right_sens_val < 500) {     //reverse the <,> signs for white line on black background
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    delay(10);
  }
  else if (left_sens_val < 500 && right_sens_val > 500) { //reverse the <,> signs for white line on black background
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    delay(10);
  }
  else if (left_sens_val < 500 && right_sens_val < 500) {  //reverse the <,> signs for white line on black background
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  else if (left_sens_val > 500 && right_sens_val > 500) {  //reverse the <,> signs for white line on black background
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }

}
