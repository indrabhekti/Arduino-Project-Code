#define LS 8 
#define RS 9 
#define M1A 10 
#define M1B 12 
#define M2A 11 
#define M2B 13 
void setup()
{
Serial.begin(9600);
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(M1A, OUTPUT);
pinMode(M1B, OUTPUT);
pinMode(M2A, OUTPUT);
pinMode(M2B, OUTPUT);
}
void loop()
{
int Right = digitalRead(LS);
int Left  = digitalRead(RS);
if((Right==0)&&(Left==0) ) 
{
digitalWrite(M1A, HIGH);
digitalWrite(M1B, LOW);
digitalWrite(M2A, HIGH);
digitalWrite(M2B, LOW);
}
if((Right==1)&&(Left==0)) 
{
digitalWrite(M1A, LOW);
digitalWrite(M1B, LOW);
digitalWrite(M2A, HIGH);
digitalWrite(M2B, LOW);
}
if((Right==0)&&(Left==1)) 
{
digitalWrite(M1A, HIGH);
digitalWrite(M1B, LOW);
digitalWrite(M2A, LOW);
digitalWrite(M2B, LOW);
}

if((Right==1)&&(Left==1)) 
{
digitalWrite(M1A, LOW);
digitalWrite(M1B, LOW);
digitalWrite(M2A, LOW);
digitalWrite(M2B, LOW);
}
}
