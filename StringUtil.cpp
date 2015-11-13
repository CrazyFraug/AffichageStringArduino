/*
   String constructors
 
 A. Bozec added d2Stringe and d2Stringf for float conversion
 
 This example code is in the public domain.
 */

#include "StringUtil.h"

// use for %sizeMax.nbDecim1e  format
String d2Stringe(double myDouble, int nbDecim1, int sizeMax)
{
   char acTmp[sizeMax+1];
   unsigned char nbDecim2 = nbDecim1;
   
   // I limit the nb of decimals
   // note: dtostre  limits decimals to 7
   if (nbDecim1 > sizeMax-7) 
       nbDecim2 = sizeMax-7;
      
   return String( dtostre(myDouble, acTmp, nbDecim2, DTOSTR_ALWAYS_SIGN) );
}

String d2Stringf(double myDouble, int nbDecim1, int sizeMax)
 {
   char acTmp[sizeMax+1];
   unsigned char nbDecim2=nbDecim1;

   if ( nbDecim1 > sizeMax-3 )  
      // too many decimals
      // decimal size: w + sign + 0 + . 
      // ex: -0.0012\0
      return d2Stringe(myDouble, nbDecim1, sizeMax);
   else if ( fabs(myDouble) >  ldexp( 1, int(1+3.33*(sizeMax-nbDecim1-2)) ) ) 
      // too big -> use exp notation
      // decimal size: w + sign + . 
      // ex: -12.3\0
      // pow(10,sizeMax-nbDecim1-2) ~= pow(2, 3.33*(sizeMax-nbDecim1-2)) = ldexp(1, 3.33*(sizeMax-nbDecim1-2))
      return d2Stringe(myDouble, nbDecim1, sizeMax);
   else if ( fabs(myDouble) * ldexp( 1, int(1+3.33*nbDecim1) ) < 1 ) 
      // too low,  decimals wont appear
      return d2Stringe(myDouble, nbDecim1, sizeMax);
   else 
      nbDecim2 = nbDecim1;

   return String( dtostrf(myDouble, -1, nbDecim2, acTmp) );
 }

 