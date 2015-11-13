/*
   String constructors
 
 Examples of how  to create strings from other data types
 
 created 27 July 2010
 modified 30 Aug 2011
 by Tom Igoe
 
 http://arduino.cc/en/Tutorial/StringConstructors

 A. Bozec added d2Strige and d2Stringf for float conversion
 
 This example code is in the public domain.
 */

#include "StringUtil.h"

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  // send an intro:
  Serial.println("\n\nString Constructors:");
  Serial.println();
}

void loop() {
  // using a constant String:
  String stringOne = "Hello String";     
  Serial.println(stringOne);      // prints "Hello String"

  // converting a constant char into a String:
  stringOne =  String('a');        
  Serial.println(stringOne);       // prints "a"

  // converting a constant string into a String object:
  String stringTwo =  String("This is a string");  
  Serial.println(stringTwo);      // prints "This is a string"

  // concatenating two strings:
  stringOne =  String(stringTwo + " with more"); 
  // prints "This is a string with more":
  Serial.println(stringOne);      

  // using a constant integer:
  stringOne =  String(13);        
  Serial.println(stringOne);      // prints "13"

  // using an int and a base:
  stringOne =  String(analogRead(A0), DEC);  
  // prints "453" or whatever the value of analogRead(A0) is
  Serial.println(stringOne);      

  // using an int and a base (hexadecimal):
  stringOne =  String(45, HEX);   
  // prints "2d", which is the hexadecimal version of decimal 45:
  Serial.println(stringOne);      

  // using an int and a base (binary)
  stringOne =  String(255, BIN);  
  // prints "11111111" which is the binary value of 255
  Serial.println(stringOne);      

  // using a long and a base:
  stringOne =  String(millis(), DEC);
  // prints "123456" or whatever the value of millis() is: 
  Serial.println(stringOne);      

  // using a float (or double) and nb of dec:
  // prints "2.534" 
  Serial.println(2.5345, 3);
  // prints "2.534" 
  Serial.println(String("d2Stringf:")+d2Stringf(2.5345, 3, 20));      
  Serial.println(25.345);
  // prints "25.3450" 
  Serial.println(String("d2Stringf:")+d2Stringf(25.345,4));      
  Serial.println(2.53e20);
  // prints "2.53e+20" 
  Serial.println(String("d2Stringf:")+d2Stringf(2.53e20,2));      
  Serial.println(2.53e10);
  // prints "25300001000.00" 
  Serial.println(String("d2Stringf:")+d2Stringf(2.53e10,2));      
  Serial.println(2.53e9);
  // prints "2529999900.00" 
  Serial.println(String("d2Stringf:")+d2Stringf(2.53e9,2));      
  Serial.println(2.53e8);
  // prints "253000000.00" 
  Serial.println(String("d2Stringf:")+d2Stringf(2.53e8,2));      
  Serial.println(2.53e-5);
  // prints "2.5300e-05"
  Serial.println(String("d2Stringf4:")+d2Stringf(2.53e-5,4));
  // prints "0.00003" 
  Serial.println(String("d2Stringf5:")+d2Stringf(2.53e-5,5));
  Serial.println(-2.53);
  // prints "-2.530" 
  Serial.println(String("d2Stringf:")+d2Stringf(-2.53,3)); 
  Serial.println(-2.12345e2);
  // prints "-212.345000000000000" 
  Serial.println(String("d2Stringf 15:")+d2Stringf(-2.12345e2,15));
  // prints "-2.1234500e+06" 
  Serial.println(String("d2Stringf 17:")+d2Stringf(-2.12345e2,16));
  // prints "-2.1234500e+07" 
  Serial.println(String("d2Stringf 15:")+d2Stringf(-2.12345e2*10,15));
  
  Serial.println(-2.5345e6);
  // prints "-2.535e+06" 
  Serial.println(String("d2Stringe:")+d2Stringe(-2.5345e6,3));      
  Serial.println(-2.5345e2);
  // prints "-2.5345000e+02"
  Serial.println(String("d2Stringe:")+d2Stringe(-2.5345e2,13));      
  Serial.println(-2.5345e2);
  // prints "-2.5345000e+02"
  Serial.println(String("d2Stringe:")+d2Stringe(-2.5345e2,14));      
  Serial.println(-2.5345e2);
  // prints "-2.534500e+02"
  Serial.println(String("d2Stringe:")+d2Stringe(-2.5345e2,6));      
  
  // do nothing while true:
  while(true);

}
