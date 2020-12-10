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
      return getSubtracao(primeiro, segundo, base);
    }

  private:
    string primeiro, segundo;

    string getSubtracao(string numeroUm, string numeroDois, int base)
    {
      string um = numeroUm;
      string dois = numeroDois;
      int size1 = numeroUm.length();
      int size2 = numeroDois.length();
      bool resultNegativo = false;
      int size;
      
      

      if(numeroUm.length() > numeroDois.length())
        size = size1;
      else if(numeroUm.length() < numeroDois.length())
      {
        size = size2;
        um = segundo;
        dois = primeiro;
        resultNegativo = true;
      }      
      else
      {
        
        for(int i =0; i <= size1-1; i++)
        {
          if(numeroUm[i] == '.')
            continue;
          size = size1;
          char atual1 = numeroUm[i];
          char atual2 = numeroDois[i];
          int val1;
          int val2;
          
          if(isdigit(atual1))
            val1 = atual1 - 48;
          else
            val1 = charToInt(atual1);
          if(isdigit(atual2))
            val2 = atual2 - 48;
          else
            val2 = charToInt(atual2);

          if(val1 > val2)
          {
            
            break;
          }
          if (val1 < val2)
          {
            um = numeroDois;
            dois = numeroUm;
            resultNegativo = true;
            break;
          }
        }
      }
      bool peso = false;


      for(int i= size-1; i>=0;i--)
      {

        if(i >= size1 || i >= size2)
          break;
        if(um[i] == '.')
          continue;

        char atual1 = um[i];
        char atual2 = dois[i];
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
          {
            int valor = charToInt(um[i]) - val2;
            if(valor >= 10)
              um[i] = intToChar(valor);
            else
              um[i] = valor + '0';
          }
        }
        else
        {
          for(int n = i - 1; n >= 0; n--)
          {
            if(um[n] == '.')
              continue;
            if(isalpha(um[n]) || um[n] - '0' > 0)
            {
              int valAtual;
              if(isdigit(um[n]))
                valAtual = um[n] - '0';
              else
                valAtual = charToInt(um[n]);
              valAtual--;
              val1 += base;
              val1 -= val2;
              if(val1 >= 10)
                um[i] = intToChar(val1);
              else
                um[i] = val1 + '0';
              if(valAtual >= 10)
                um[n] = intToChar(valAtual);
              else
                um[n] = valAtual + '0';

              for(int x = n + 1; x < i; x++)
              {
                if(um[x] == '.')
                  continue;
                int valAnterior;
                if(isdigit(um[x]))
                  valAnterior = um[n] - '0';
                else
                  valAnterior = charToInt(um[x]);
                valAnterior--;
                if(valAtual >= 10)
                  um[x] = intToChar(valAnterior);
                else
                  um[x] = valAnterior + '0';
              }
              break;
            }
            else
              continue;
          }
        }
        
      }
      
      if(resultNegativo)
          um = "-" + um;
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