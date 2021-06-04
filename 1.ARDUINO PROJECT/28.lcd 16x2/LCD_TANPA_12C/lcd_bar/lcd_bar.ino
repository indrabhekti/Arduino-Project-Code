
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const  int  LCD_NB_ROWS  =  2 ;
const  int  LCD_NB_COLUMNS  =  16 ;


//* Custom characters 
byte  START_DIV_0_OF_1 [ 8 ]  =  {
  B01111 ,
  B11000 ,
  B10000 ,
  B10000 ,
  B10000 ,
  B10000 ,
  B11000 ,
  B01111
};  // Char start 0/1

byte  START_DIV_1_OF_1 [ 8 ]  =  {
  B01111 ,
  B11000 ,
  B10011 ,
  B10111 ,
  B10111 ,
  B10011 ,
  B11000 ,
  B01111
};  // Char start 1/1

byte  DIV_0_OF_2 [ 8 ]  =  {
  B11111 ,
  B00000 ,
  B00000 ,
  B00000 ,
  B00000 ,
  B00000 ,
  B00000 ,
  B11111
};  // Middle tank 0/2

byte  DIV_1_OF_2 [ 8 ]  =  {
  B11111 ,
  B00000 ,
  B11000 ,
  B11000 ,
  B11000 ,
  B11000 ,
  B00000 ,
  B11111
};  // Middle tank 1/2

byte  DIV_2_OF_2 [ 8 ]  =  {
  B11111 ,
  B00000 ,
  B11011 ,
  B11011 ,
  B11011 ,
  B11011 ,
  B00000 ,
  B11111
};  // Middle tank 2/2

byte  END_DIV_0_OF_1 [ 8 ]  =  {
  B11110 ,
  B00011 ,
  B00001 ,
  B00001 ,
  B00001 ,
  B00001 ,
  B00011 ,
  B11110
};  // Char end 0/1

byte  END_DIV_1_OF_1 [ 8 ]  =  {
  B11110 ,
  B00011 ,
  B11001 ,
  B11101 ,
  B11101 ,
  B11001 ,
  B00011 ,
  B11110
};  // Char thin 1/1



void  setup_progressbar ()  {

  // Store custom characters in LCD display memory 
  lcd . createChar ( 0 ,  START_DIV_0_OF_1 );
  lcd . createChar ( 1 ,  START_DIV_1_OF_1 );
  lcd . createChar ( 2 ,  DIV_0_OF_2 );
  lcd . createChar ( 3 ,  DIV_1_OF_2 );
  lcd . createChar ( 4 ,  DIV_2_OF_2 );
  lcd . createChar ( 5 ,  END_DIV_0_OF_1 );
  lcd . createChar ( 6 ,  END_DIV_1_OF_1 );
}




void  draw_progressbar ( byte  percent )  {

  //Display the new value in numeric form on the first line 
  lcd . setCursor ( 0 ,  0 );
  lcd . print ( percent );
  lcd . print ( F ( "%" ));
  // NB The two spaces at the end of the line are used to erase the figures of the percentage
  // previous when changing from a two or three digit value to a two or one digit value.

  //Move the cursor to the second line * /
  lcd . setCursor ( 0 ,  1 );

  //Map range (0 ~ 100) to range (0 ~ LCD_NB_COLUMNS * 2 - 2) * /
  byte  nb_columns  =  map ( percent ,  0 ,  100 ,  0 ,  LCD_NB_COLUMNS  *  2  -  2 );
  // Each character displays 2 vertical bars, but the first and last character displays only one.

  //Draw each character on the line * /
  for  ( byte  i  =  0 ;  i  <  LCD_NB_COLUMNS ;  ++ i )  {

    if  ( i  ==  0 )  {  // First case
  
      //Display the starting char according to the number of columns * /
      if  ( nb_columns  >  0 )  {
        lcd . write ( 1 );  // Char start 1/1
        nb_columns  -=  1 ;
  
      }  else  {
        lcd . write (( byte )  0 );  // Char start 0/1
      }
  
    }  else  if  ( i  ==  LCD_NB_COLUMNS  - 1 )  {  // Last case
  
      //isplay the end char according to the number of columns * /
      if  ( nb_columns  >  0 )  {
        lcd . write ( 6 );  // Char thin 1/1
  
      }  else  {
        lcd . write ( 5 );  // Char end 0/1
      }
  
    }  else  {  // Other boxes
  
      //Display the correct char according to the number of columns * /
      if  ( nb_columns  >=  2 )  {
        lcd . write ( 4 );  // Char div 2/2
        nb_columns  -=  2 ;
  
      }  else  if  ( nb_columns  ==  1 )  {
        lcd . write ( 3 );  // Char div 1/2
        nb_columns  -=  1 ;
  
      }  else  {
        lcd . write ( 2 );  // Char div 0/2
      }
    }
  }
}


//  Setup function () * /
void  setup () {

  // Initializes the LCD screen * /
  lcd . begin ( LCD_NB_COLUMNS ,  LCD_NB_ROWS );
  setup_progressbar ();
  lcd . clear ();
}


void  loop () {

  //Percentage value of the progress bar * /
  static  byte  percent  =  0 ;

  //isplay the value * /
  draw_progressbar ( percent );

  //Increment the percentage * /
  if  ( ++ percent  ==  101 )  {
    // Return to zero if the percentage exceeds 100%
    percent  =  0 ;
    delay ( 1000 );
  }

  //waktu bar
  delay ( 500) ;
}
