void setup()

{

pinMode(4, OUTPUT);

pinMode(5, OUTPUT);

pinMode(6, OUTPUT);

pinMode(7, OUTPUT);



// menjadikan PIN 0, 1, 2, 3, dan 4 sebagai OUTPUT

}


void loop()

{

//menyala secara bergilir


digitalWrite(4, HIGH);

digitalWrite(5, LOW);

digitalWrite(6, LOW);

digitalWrite(7, LOW);



delay(100);


digitalWrite(4, LOW);

digitalWrite(5, HIGH);

digitalWrite(6, LOW);

digitalWrite(7, LOW);



delay(100);


digitalWrite(4, LOW);

digitalWrite(5, LOW);

digitalWrite(6, HIGH);

digitalWrite(7, LOW);



delay(100);


digitalWrite(4, LOW);

digitalWrite(5, LOW);

digitalWrite(6, LOW);

digitalWrite(7, HIGH);



delay(100);






}
