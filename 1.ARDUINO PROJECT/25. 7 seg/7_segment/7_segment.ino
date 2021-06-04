byte numbers[10] = { 
B11111100, B01100000, B11011010, B11110010, B01100110, 
B10110110, B10111110, B11100000, B11111110, B11110110 
};
void setup() { 
for(int i = 2; i <= 8; i++)
{
pinMode(i, OUTPUT); 
}

pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT);
}

int counter = 0;
bool go_by_switch = true;
int last_input_value = LOW;

void loop() {
if(go_by_switch) {
int switch_input_value = digitalRead(9);
if(last_input_value == LOW && switch_input_value == HIGH) {
delay(100);
counter = (counter + 1) % 10;
}
last_input_value = switch_input_value;
} 
else {
delay(500); 
counter = (counter + 1) % 10;
}
writeNumber(counter);
}

void writeNumber(int number) {
if(number < 0 || number > 9)
{
return;
}

byte mask = numbers[number];
byte currentPinMask = B10000000;

for(int i = 2; i <= 8; i++)
{
if(mask & currentPinMask) digitalWrite(i,HIGH);
else digitalWrite(i,LOW);
currentPinMask = currentPinMask >> 1;
}
}
