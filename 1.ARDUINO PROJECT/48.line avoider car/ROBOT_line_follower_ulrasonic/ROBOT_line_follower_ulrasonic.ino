#define CW  0
#define CC 1
#define MOTOR_A 0
#define MOTOR_B 1

const int E1 = 10;
const int E2 = 11;
const int M1 = 12;
const int M2 = 13;

const int MAX = 250;
const int MEDB = 200;
const int MEDA = 150;
const int MIN = 100;

const int SENSOR1 = 6;
const int SENSOR2 = 7;

const int TRIG = 4;
const int ECHO = 5;

int A, B, DIST;
long DUR;
int SPD = MIN;
int length = 10;

void setup(){
 
pinMode(E1, OUTPUT);
pinMode(E2, OUTPUT);
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT);

pinMode(SENSOR1, INPUT);
pinMode(SENSOR2, INPUT);
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);

 
digitalWrite(E1, LOW);
digitalWrite(E2, LOW);
digitalWrite(M1, LOW);
digitalWrite(M2, LOW);
}


void drive(byte motor, byte dir,byte spd)
{
if (motor == MOTOR_A)
{
digitalWrite(M1, dir);
analogWrite(E1, spd);
}
else if (motor == MOTOR_B)
{
digitalWrite(M2, dir);
analogWrite(E2, spd);
} 
}

void stop(byte motor)
{
drive( motor, 0, 0);
}

void loop() {
 
A = digitalRead(SENSOR1);
B = digitalRead(SENSOR2); 
digitalWrite(TRIG, LOW);
delayMicroseconds(2);
digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);

DUR = pulseIn(ECHO, HIGH);
DIST = (DUR/2) / 29.1;
if (DIST < length) {
stop(MOTOR_A);
stop(MOTOR_B);
}
else {
if (A == 1) {                       
drive(MOTOR_A,CC,SPD); 
}
else if (A == 0) {              
drive(MOTOR_A,CW,SPD);  
}
if (B == 1) {                      
drive(MOTOR_B,CC,SPD); 
}
else if (B == 0) {                 
drive(MOTOR_B,CW,SPD);  
}   
}
}
