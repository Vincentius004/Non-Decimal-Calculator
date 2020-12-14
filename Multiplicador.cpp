#include <iostream>
#include<string>
#include <stdlib.h>
#include <math.h>
#include "Multiplicador.h"
#include "Somador.h"
using std::string;

    string Multiplicador::multiplicar(string numeroUm, string numeroDois, int base)
    {
      ajeitarStrings(numeroUm, numeroDois);
      return getMultiplicacao(primeiro, segundo, base);
    }

    string Multiplicador::getMultiplicacao(string numeroUm, string numeroDois, int base)
    {
      string um = primeiro;
      string dois = segundo;
      int size1 = primeiro.length();
      int size2 = segundo.length();
      string resultado = "0";
      bool peso =false;
      int qtdSoma = 0;
      int aux;
      int quociente = 0;
      int resto;
      string umaSoma = "";

      if(casasVirgula1 == 0 || casasVirgula2 == 0)
        qtdSoma = size1 * size2;
      else if(casasVirgula1 == 0 || casasVirgula2 > 0)
        qtdSoma = size1 * (size2 - 1);
      else if(casasVirgula1 > 0 || casasVirgula2 == 0)
        qtdSoma = (size1 - 1) * size2;
      else
        qtdSoma = (size1 - 1) * (size2 - 1);
      string soma[qtdSoma];
      int indiceSoma = 0;

      for(int i = size1-1; i>=0;i--)
      {
        if(i >= size1 || i >= size2)
          break;
        if(dois[i] == '.')
          continue;
        char atual2 = dois[i];
        int val2;
        if(isdigit(atual2))
          val2 = atual2 - '0';
        else
          val2 = charToInt(atual2);
        
        for(int y = size1-1;y>=0;y--)
        {        
          if(um[y] == '.')
            continue;
          char atual1 = um[y];
          int val1;
          if(isdigit(atual1))
            val1 = atual1 - '0';
          else
            val1= charToInt(atual1);

          aux = val1*val2;
          aux +=quociente;
          quociente = aux/base;
          resto = aux%base;


           if(resto<10) 
          umaSoma = (char)(resto + '0') + umaSoma;
          else 
          umaSoma= (intToChar(resto)) + umaSoma;

          if(y == 0) 

          { 
            if (quociente >0) 
            { 
              if(quociente<10) umaSoma = (char)(quociente +'0') + umaSoma;
             else umaSoma = intToChar(quociente) +umaSoma; 
            } 
          }

        }
        
        int a=0;
        while(a < indiceSoma)
        {
          umaSoma += "0";
          a++;
        }
        soma[indiceSoma] = umaSoma;
        
        indiceSoma++;
        umaSoma="";  
        quociente=0;     
      }

      for(int i = 0; i < qtdSoma; i++)
      {
        Somador s;
        resultado =  s.somar(resultado, soma[i], base);
      }

      string resultado2 = "";
      for(int i = 0; i < resultado.length(); i++)
      {
        if((resultado.length() - i) == casasVirgula1 + casasVirgula2)
          resultado2 += ".";
        resultado2 += resultado[i];
      }
      
      
      string resultadoFormatado;
      if(casasVirgula1 == 0 && casasVirgula2 == 0)
      {
        int i=0;
        while((char)resultado[i]==48)
        {
          i++;
        }
        if(i == resultado.length())
        resultadoFormatado +="0";
        for(;i<resultado.length();i++)
        {

         resultadoFormatado = resultadoFormatado + resultado[i];
        }

        if((primeiroNegativo && !segundoNegativo) || (!primeiroNegativo && segundoNegativo))
          resultadoFormatado = "-" + resultadoFormatado;
       
         return resultadoFormatado;
        }
      else
      {
        int i=0;
        while((char)resultado2[i]==48)
        {
         i++;
        }

        for(;i<resultado2.length();i++)
        {
          if((char)resultado2[i]==46)
          resultadoFormatado = resultadoFormatado+ "0";
      
         resultadoFormatado = resultadoFormatado + resultado2[i];
        }

        if((primeiroNegativo && !segundoNegativo) || (!primeiroNegativo && segundoNegativo))
          resultadoFormatado = "-" + resultadoFormatado;
        
        return resultadoFormatado;
      }
    }

    int Multiplicador::charToInt(char letter)  // retorna a letra equivalente a um numero
    {
      return (int) (letter - 55);
    }

    char Multiplicador::intToChar(int number)  // retorna o numero equivalente a uma letra
    {
      return (char) (number + 55);
    }

    void Multiplicador::ajeitarStrings(string numeroUm, string numeroDois)
    {
      
      primeiro = numeroUm;
      segundo = numeroDois;
      string primeiroAntes = "";
      string primeiroDepois = "";
      string segundoAntes = "";
      string segundoDepois = "";
      bool temVirgula1 = false;
      bool temVirgula2 = false;

      if((char)primeiro[0] == 45)  // se o primeiro caractere for "-"
      {
        string aux = "";
        for(int i = 1; i < primeiro.length(); i++)
        {
          aux += primeiro[i];
        }
        primeiro = aux;
        primeiroNegativo = true;
      }

      if((char)segundo[0] == 45)  // se o primeiro caractere for "-"
      {
        string aux = "";
        for(int i = 1; i < segundo.length(); i++)
        {
          aux += segundo[i];
        }
        segundo = aux;
        segundoNegativo = true;
      }

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
        if(temVirgula1)
          casasVirgula1++;
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
        if(temVirgula2)
          casasVirgula2++;
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

      if(primeiroDepois.length()-1 > segundoDepois.length())
      {
        while(primeiroDepois.length() > segundoDepois.length())
        {
          segundoDepois += "0";
        }
      }

      else
      {
        while(segundoDepois.length()-1 > primeiroDepois.length())
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
        {
          segundo += "0";
          casasVirgula2++;
        }
      }
      else if (segundo.length() > primeiro.length())
      {
        primeiro += ".";
        while(primeiro.length() < segundo.length())
        {
          primeiro += "0";
          casasVirgula1++;
        }
      }
    }