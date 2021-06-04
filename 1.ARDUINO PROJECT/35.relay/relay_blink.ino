int relay = 8; // relay turns trigger signal - active high;
void setup ()
{
  pinMode (relay, OUTPUT); // Define port attribute is output;
}
void loop ()
{
  digitalWrite (relay, HIGH); // relay conduction;
  delay (5000);
  digitalWrite (relay, LOW); // relay switch is turned off;
  delay (5000);
}
