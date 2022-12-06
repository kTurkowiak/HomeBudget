#ifndef SUPPORTMETHOD_H
#define SUPPORTMETHOD_H

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class SupportMethod
{



public:
   static char loadChar();
   static string loadLine();
   static string convertIntToString(int number);
   static int convertStringToInt(string number);
   static string convertFloatToString (float number);
   static float convertStringToFloat (string number);

};




#endif
