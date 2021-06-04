//CODE MADE BY YADRATOREX

byte crosswalk_button=0;    //That will memorize the state of the button, if it's pressed or not

void setup() {
  pinMode(11, OUTPUT); //RED LED OF THE TRAFFIC LIGHTS
  pinMode(12, OUTPUT); //ORANGE LED OF THE TRAFFIC LIGHTS
  pinMode(13, OUTPUT); //GREEN LED OF THE TRAFFIC LIGHTS
  pinMode(2, INPUT);   //BUTTON
  pinMode(6, OUTPUT);  //GREEN LED OF THE CROSSWALK
  pinMode(7, OUTPUT);  //RED LED OF THE CROSSWALK
  pinMode(8, OUTPUT);  //Buzzer
}

void loop() {
  
  crosswalk_button=digitalRead(2);  //That will read the state of the button, if it's pressed or not
  
   if (crosswalk_button == 0) //If you press the button for the crosswalk, the red traffic light will turn on with the green one for the crosswalk
  {
    delay(3000);
    digitalWrite(13,LOW);     //TURN OFF THE GREEN LED OF THE TRAFFIC LIGHTS
    digitalWrite(12,HIGH);    //TURN ON ORANGE LED OF THE TRAFFIC LIGHTS
    delay(3000);              //DELAY TIME FOR THE ORANGE LED
    digitalWrite(12,LOW);     //TURN OFF ORANGE LED OF THE TRAFFIC LIGHTS
    digitalWrite(11,HIGH);    //TURN ON RED LED OF THE TRAFFIC LIGHTS
    delay(2000);              //WAIT FOR TURN ON THE GREEN LED OF THE CROSSWALK
    digitalWrite(7,LOW);      //TURN OFF THE RED LED OF THE CROSSWALK
    digitalWrite(6,HIGH);     //TURN ON THE GREEN LED OF THE CROSSWALK
    delay(8000);              //DELAY TIME FOR THE GREEN LED OF THE CROSSWALK
    
    if(6,HIGH)               //Now, when the delaying time run out, the buzzer starts beeping
    {
      tone(8,2900,200);      //Beeps out of time for the crosswalk
      delay(300);
      tone(8,2900,200);
      delay(300);
      tone(8,2900,200);
      delay(300);
      tone(8,2900,200);
      delay(300);
      tone(8,2900,200);
      delay(300);
      tone(8,2900,200);
      delay(300);
      tone(8,2900,200);
      delay(300);
      tone(8,2900,200);
      delay(300);
      tone(8,2900,200);
      delay(300);
      digitalWrite(6,LOW);  //TURN OFF THE GREEN LED OF THE CROSSWALK
      digitalWrite(7,HIGH); //TURN ON THE RED LED OF THE CROSSWALK
    }
    
    delay(2000);  //Wait two seconds for go green the traffic light and red for the crosswalk
    
  }
  
   else     //When the button is not pressed, the green traffic light will be on with the red one for the crosswalk
   {

    digitalWrite(13, HIGH);     //TURN ON THE GREEN LED OF THE TRAFFIC LIGHTS
    digitalWrite(7,HIGH);       //TURN ON THE RED LED OF THE CROSSWALK
    digitalWrite(6,LOW);        //TURN ON THE OTHER LED LIGHTS
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);

  }

 
}

//YADRATOREX 11-01-2017
