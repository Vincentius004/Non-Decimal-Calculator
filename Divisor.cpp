#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
#include <math.h>
#include "Divisor.h"
#include "Somador.h"
#include "Subtrador.h"
using std::string;

  string Divisor::dividir(string numeroUm, string numeroDois, int base)
    {
      ajeitarStrings(numeroUm, numeroDois);
      if(segundo == "0")
        return "Infelizmente isso é impossível :(";
      return getDivisao(primeiro, segundo, base);
    }

    string Divisor::getDivisao(string numeroUm,string numeroDois,int base)
    {
      
      string um = numeroUm;
      bool decimal = false;
      Somador somador;
      Subtrador subtrador;
      string resultado = "";

      bool negativo = false;
      while(!negativo)
      {
        string subtraido = subtrador.subtrair(um, numeroDois, base);
        for(int j = 0; j < subtraido.length(); j++)
          if(subtraido[j] == '-')
            negativo = true;
        if(negativo)
        {
          if(!decimal)
            resultado += "0.";
          um += "0";
          decimal = true;
        }
        else
          break;
      }

      for(;;)
      {
        string numeroSubtrair = "0";
        string i = "0";
        bool achou = false;
        while(!achou)
        {
          
          i = somador.somar(i, "1", base);
          numeroSubtrair = somador.somar(numeroSubtrair, numeroDois, base);
          string subtraido = subtrador.subtrair(um, numeroSubtrair, base);
          bool negativoAtual = false;
          for(int j = 0; j < subtraido.length(); j++)
            if(subtraido[j] == '-')
              negativoAtual = true;
          if(negativoAtual)
          {
            numeroSubtrair = subtrador.subtrair(numeroSubtrair, numeroDois, base);
            i = subtrador.subtrair(i, "1", base);
            achou = true;
          }
        }
        string resto = subtrador.subtrair(um, numeroSubtrair, base);
        if((char)resto[0] == 48)
        {
          resultado += i;
          break;
        }
        else
        {
          resultado += i;
          if(resultado.length()>13)
            break;
          um = resto;
          string subtraido = subtrador.subtrair(um, numeroDois, base);
          bool negativoAtual = false;
          for(int j = 0; j < subtraido.length(); j++)
            if(subtraido[j] == '-')
              negativoAtual = true;
          if(negativoAtual)
          {
            if(!decimal)
              resultado += ".";
            um += "0";
            decimal = true;
            continue;
          }
          else
            continue;
        }
      }
    if((primeiroNegativo && !segundoNegativo) || (!primeiroNegativo && segundoNegativo))
        resultado = "-"+resultado;

      return resultado;
      
    }

    int Divisor::charToInt(char letter)
    {
      return (int) (letter - 55);
    }

    char Divisor::intToChar(int number)
    {
      return (char) (number + 55);
    }

    void Divisor::ajeitarStrings(string numeroUm, string numeroDois)
    {
      primeiro = numeroUm;
      segundo = numeroDois;
      string primeiroAntes = "";
      string primeiroDepois = "";
      string segundoAntes = "";
      string segundoDepois = "";
      bool temVirgula1 = false;
      bool temVirgula2 = false;

      if((char)primeiro[0] == 45)
      {
        string aux = "";
        for(int i = 1; i < primeiro.length(); i++)
        {
          aux += primeiro[i];
        }
        primeiro = aux;
        primeiroNegativo = true;
      }

      if((char)segundo[0] == 45)
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


      if(primeiroDepois.length() > segundoDepois.length())
      {
        while(segundoDepois.length() < primeiroDepois.length())
        {
          segundoDepois += "0";
          if(casasVirgula2 == 0)
            segundoAntes += "0";
        }
      }
      else
      if(primeiroDepois.length() < segundoDepois.length())
      {
        while(segundoDepois.length() > primeiroDepois.length())
        {
          primeiroDepois += "0";
          if(casasVirgula1 == 0)
            primeiroAntes += "0";
        }
      }

      if(temVirgula1)
        primeiro = primeiroAntes +  primeiroDepois;
      else
        primeiro = primeiroAntes;
      
      if(temVirgula2)
        segundo = segundoAntes +  segundoDepois;
      else
        segundo = segundoAntes;      
    }