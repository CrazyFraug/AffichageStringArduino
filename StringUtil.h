/*
   API to build a message for serial com
 
 A. Bozec added d2Stringe and d2Stringf for float conversion
 
 This example code is in the public domain.
 */
#ifndef STRINGUTIL_h
#define STRINGUTIL_h
 
#include <Arduino.h>

// dtostre safe
String d2Stringe(double myDouble, int nbDecim1, int sizeMax=20);

// dtostrf safe
String d2Stringf(double myDouble, int nbDecim1, int sizeMax=20);


template <class T>
String buildMsgArray(int id, char *tag, T *array, int size) {
  String inStringResult("{\"id\":");
  inStringResult = inStringResult + id + ",\"" + tag + "\":[" ;
  
  for (int i=0; i<size; i++)
    {
	if (i>0)
      inStringResult += ",";
	inStringResult += String(array[i]);
	}
  
  inStringResult += "]}";
  
  return inStringResult;  
}

#endif