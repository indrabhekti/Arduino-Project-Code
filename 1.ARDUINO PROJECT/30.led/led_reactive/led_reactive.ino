int soundPin = A0; //input sound sesnsor pin A0
int LED1 = 4; //led di pin 4-13
int LED2 = 5;
int LED3 = 6;
int LED4 = 7;
int LED5 = 8;
int LED6 = 9;
int LED7 = 10;
int LED8 = 11;
int LED10 = 12;
int LED9 = 13;

void setup()
{
Serial.begin(9600);//serial 
pinMode(LED1, OUTPUT);//identifikasi pin 4-13 sebagai output
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);
pinMode(LED7, OUTPUT);
pinMode(LED8, OUTPUT);
pinMode(LED9, OUTPUT);
pinMode(LED10, OUTPUT);
}

void loop()
{
long sum = 0;
for(int i=0; i<100; i++) 
{
sum += analogRead(soundPin);
}

sum = sum/100; //nilai analog di bagi 100


if (sum>=100) digitalWrite(LED1, HIGH); else digitalWrite(LED1, LOW); //nilai sum di sesuaikan
if (sum>=200) digitalWrite(LED2, HIGH); else digitalWrite(LED2, LOW);
if (sum>=300) digitalWrite(LED3, HIGH); else digitalWrite(LED3, LOW);
if (sum>=350) digitalWrite(LED4, HIGH); else digitalWrite(LED4, LOW);
if (sum>=400) digitalWrite(LED5, HIGH); else digitalWrite(LED5, LOW);
if (sum>=450) digitalWrite(LED6, HIGH); else digitalWrite(LED6, LOW);
if (sum>=500) digitalWrite(LED7, HIGH); else digitalWrite(LED7, LOW);
if (sum>=550) digitalWrite(LED8, HIGH); else digitalWrite(LED8, LOW);
if (sum>=600) digitalWrite(LED9, HIGH); else digitalWrite(LED9, LOW);
if (sum>=650) digitalWrite(LED10, HIGH); else digitalWrite(LED10, LOW);
delay(10); 
Serial.println(sum);
}
