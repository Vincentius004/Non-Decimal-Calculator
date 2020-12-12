#ifndef SOMADOR_H
#define SOMADOR_H
#include <iostream>
#include<string>
#include <stdlib.h>
#include <math.h>
using std::string;

class Somador{
    public:
      string somar(string numeroUm, string numeroDois, int base);
    
    private:  
      string primeiro;
      string segundo;
      bool primeiroNegativo = false;
      bool segundoNegativo = false;
      string getSoma(string numeroUm, string numeroDois, int base);
      int charToInt(char letter);
      char intToChar(int number);
      void ajeitarStrings(string numeroUm, string numeroDois);
};

#endif