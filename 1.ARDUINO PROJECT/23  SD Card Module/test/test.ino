#include <SD.h>
#include <SPI.h>

File myFile;

#define RedLED 6
#define GreenLED 7
#define YellowLED 8
#define button 9
#define AnalogPin A0

int pinoSS = 10; // Pin 53 para Mega / Pin 10 para UNO

unsigned long int tempo_atual = 0; //Variable used to store the current time of code execution
unsigned long ultimo_tempo = 0; //Variable used to store the last value stored in the variable tempo_atual

int DigitalValue = 0;

byte samples = 0, value = 0; //Sample is a variable to count until 10 and value is used count the number of times that user store 10 samples
bool ButtonControl = 0, control = 0;

void setup()
{
  Serial.begin(9600); // Define BaundRate

  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);

  pinMode(pinoSS, OUTPUT); // Pin pinoSS like a output

  if (SD.begin())
  { // Inicializa o SD Card
    Serial.println("SD Card pronto para uso."); // Imprime na tela
  }
  else
  {
    Serial.println("Falha na inicialização do SD Card.");
    digitalWrite(RedLED, HIGH);
    return;
  }

}

void loop()
{

  bool pino = digitalRead(button);

  //Condicao para detectar quando o botao e pressionado
  if (pino == 1 && control == 0 && ButtonControl == 0)
  {
    myFile = SD.open("silicioslab.txt", FILE_WRITE); // Create/Open File the txt
    delay(500);
    ButtonControl = 1;
    value++;
    myFile.print("sample: ");
    myFile.println(value);
    samples = 0;
  }

  tempo_atual = millis();

  if ((ButtonControl == 1) && (tempo_atual - ultimo_tempo >= 1000) && samples < 10 && control == 1)
  {
    DigitalValue = analogRead(AnalogPin);
    myFile.println(DigitalValue);
    control = 0;
    ultimo_tempo = tempo_atual;//Store the actual time
    samples++;
    digitalWrite(YellowLED, HIGH);
  }

  if (samples >= 10)
  {
    digitalWrite(YellowLED, LOW);
    myFile.close();
    ButtonControl = 0;
    digitalWrite(GreenLED, HIGH);
  }

  control = control ^ 1;
}
