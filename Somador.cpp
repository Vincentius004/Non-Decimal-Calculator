#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
#include <math.h>
using std::string;

class Somador{

  public:
    static string somar(string numeroUm, string numeroDois, int base)
    {
      return getSoma(numeroUm, numeroDois, base);
    }
  
  private:
    static string getSoma(string numeroUm, string numeroDois, int base)
    {
      string um = numeroUm;
      string dois = numeroDois;
      int size1 = numeroUm.length();
      int size2 = numeroUm.length();
      int size;
      if(size1 > size2)
        size = size1;
      else
        size = size2;
      bool peso = false;

      for(int i = size - 1; i >= 0; i--)
      {
        if(i >= size1 || i >= size2)
          break;
        char atual1 = numeroUm[i];
        char atual2 = numeroDois[i];
        
          int val1;
          int val2;
          if(isdigit(atual1))
            val1 = atual1 - '0';
          else
            val1 = charToInt(atual1);
          if(isdigit(atual2))
            val2 = atual2 - '0';
          else
            val2 = charToInt(atual2);
          if(peso)
          {
            if(isdigit(um[i - 1]))
              val1 += 1;
            else
              um[i - 1] = intToChar(charToInt(um[i - 1]) + 1);
          }
          if(val1 + val2 < base)
          {
            um[i] = (val1 + val2) + '0';
            peso = false;
          }
          else
          {
            um[i] = ((val1 + val2) - base) + '0';
            if(i - 1 < 0)
            {
              um = "1" + um;
              continue;
            }
            peso = true;
          }
        
      }
      
      return um;
    }

    static int charToInt(char letter)
    {
      return (int) (letter - 55);
    }

    static char intToChar(int number)
    {
      return (char) (number + 48);
    }

};