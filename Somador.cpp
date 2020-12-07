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

      for(int i = 0; i < size1; i++)
      {
        char atual1 = numeroUm[i];
        char atual2 = numeroDois[i];
        if(isdigit(atual1))
        {
          int val1 = atual1 - '0';
          int val2 = atual2 - '0';
          if(val1 + val2 < base)
            um[i] = (val1 + val2) + '0';
          else
          {
            int val11 = um[i + 1] - '0';
            um[i + 1] = (val11 + 1) + '0';
            um[i] = ((val1 + val2) - base) + '0';
          }
        }
        cout<<"aaa: " + um<<endl;
      }
      
      return um;
    }

};