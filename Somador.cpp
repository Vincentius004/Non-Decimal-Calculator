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

    string somar(string numeroUm, string numeroDois, int base)
    {
      ajeitarStrings(numeroUm, numeroDois);
      return getSoma(primeiro, segundo, base);
    }
  
  private:
    string primeiro, segundo;

    string getSoma(string numeroUm, string numeroDois, int base)
    {
      string um = numeroUm;
      string dois = numeroDois;
      int size1 = numeroUm.length();
      int size2 = numeroDois.length();
      
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
        if(um[i] == '.')
          continue;
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
            if(isdigit(um[i]))
            {
              val1 += 1;
              um[i] = intToChar(val1);
            }
            else
            {
              um[i] = intToChar(charToInt(um[i]) + 1);
              val1++;
            }

          }
          if(val1 + val2 < base)
          {
            if(val1 + val2 <= 9)
              um[i] = (val1 + val2) + 48;
            else
              um[i] = intToChar(val1 + val2);
            peso = false;
          }
          else
          {
            if((val1 + val2) - base <= 9)
              um[i] = ((val1 + val2) - base) + 48;
            else
              um[i] = intToChar((val1 + val2) - base);
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

    int charToInt(char letter)
    {
      return (int) (letter - 55);
    }

    char intToChar(int number)
    {
      return (char) (number + 55);
    }

    void ajeitarStrings(string numeroUm, string numeroDois)
    {
      primeiro = numeroUm;
      segundo = numeroDois;
      string primeiroAntes = "";
      string primeiroDepois = "";
      string segundoAntes = "";
      string segundoDepois = "";
      bool temVirgula1 = false;
      bool temVirgula2 = false;

      for(int i = 0; i < primeiro.length(); i++)
      {
        if(primeiro[i] == '.' || primeiro[i] == ',')
        {
          temVirgula1 = true;
          continue;
        }
        if(!temVirgula1)
          primeiroAntes += primeiro[i];
        else
          primeiroDepois += primeiro[i];
      }

      for(int i = 0; i < segundo.length(); i++)
      {
        if(segundo[i] == '.' || segundo[i] == ',')
        {
          temVirgula2 = true;
          continue;
        }
        if(!temVirgula2)
          segundoAntes += segundo[i];
        else
          segundoDepois += segundo[i];
      }

      if(primeiroAntes.length() > segundoAntes.length())
      {
        while(primeiroAntes.length() > segundoAntes.length())
        {
          segundoAntes = "0" + segundoAntes;
        }
      }

      else
      {
        while(segundoAntes.length() > primeiroAntes.length())
        {
          primeiroAntes = "0" + primeiroAntes;
        }
      }

      if(primeiroDepois.length() > segundoDepois.length())
      {
        while(primeiroDepois.length() > segundoDepois.length())
        {
          segundoDepois += "0";
        }
      }

      else
      {
        while(segundoDepois.length() > primeiroDepois.length())
        {
          primeiroDepois += "0";
        }
      }

      if(temVirgula1)
        primeiro = primeiroAntes + "." + primeiroDepois;
      else
        primeiro = primeiroAntes;
      if(temVirgula2)
        segundo = segundoAntes + "." + segundoDepois;
      else
        segundo = segundoAntes;

      if(primeiro.length() > segundo.length())
      {
        segundo += ".";
        while(segundo.length() < primeiro.length())
          segundo += "0";
      }
      else if (segundo.length() > primeiro.length())
      {
        primeiro += ".";
        while(primeiro.length() < segundo.length())
          primeiro += "0";
      }
    }

};