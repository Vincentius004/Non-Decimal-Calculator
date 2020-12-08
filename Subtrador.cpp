#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
#include <math.h>
using std::string;

class Subtrador{

  public:
    string subtrair(string numeroUm, string numeroDois, int base)
    {
      ajeitarStrings(numeroUm, numeroDois);
      return getSubtracao(numeroUm, numeroDois, base);
    }

  private:
    string primeiro, segundo;

    string getSubtracao(string numeroUm, string numeroDois, int base)
    {
      string um = primeiro;
      string dois = segundo;
      int size1 = primeiro.length();
      int size2 = segundo.length();
      
      int size;
      
      if(size1 > size2)
        size = size1;
      else
        size = size2;
      bool peso = false;


      for(int i= size-1; i>=0;i--)
      {

        if(i >= size1 || i >= size2)
          break;
        if(um[i] == '.')
          continue;

        char atual1 = primeiro[i];
        char atual2 = segundo[i];
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

        if(val1 >= val2) 
        {
          if(isdigit(um[i]))
            um[i] = ((um[i] - '0') - val2) + '0';
          else
            um[i] = intToChar(charToInt(um[i]) - val2);
        }
        else/// 100 32
        {
          for(int y = i - 1; y >= 0; y--)
          {
            if(isdigit(um[y]))
            {
              if(um[y] - 48 > 0)
              {
                
                um[y] = ((um[y] -48) - 1) + 48;
                if(isdigit(um[y + 1]))
                  um[y + 1] = (um[y + 1] - 48) + base;
                else
                  um[y + 1] = charToInt(um[y + 1]) + base;
                y++;
              }
            }
            else
            {
              if(charToInt(um[y]) > 0)
              {
                um[y] = (charToInt(um[y]) - 1) + 48;
                if(isdigit(um[y + 1]))
                  um[y + 1] = (um[y + 1] - 48) + base;
                else
                  um[y + 1] = charToInt(um[y + 1]) + base;
                y++;
              }
            }
          }
        }
        return um;
      }
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
    }

};