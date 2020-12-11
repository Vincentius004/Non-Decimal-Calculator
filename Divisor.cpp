#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
#include <math.h>
using std::string;

class Divisor{

  public:
  string dividir(string numeroUm, string numeroDois, int base)
    {
      ajeitarStrings(numeroUm, numeroDois);
      cout<<"MR potato head "<<primeiro<<endl;
      cout<<"ndynui3 "<<segundo<<endl;
      return getDivisao(primeiro, segundo, base);
      
    }

  private:
  string primeiro, segundo;
  int casasVirgula1 = 0;
  int casasVirgula2 = 0;

    string getDivisao(string numeroUm,string numeroDois,int base)
    {
      
      Multiplicador multi;
      Subtrador sub;
      string multiplosDivisor[base];
      string maiorMultiplo;
      string algarismoSignificativos;
    int i = 0;

      for( i=0;i<base;i++)
      {
        
        if(i <10)
        {
          string s(1,i+'0');
          cout<<"numeroDois"<<numeroDois<<endl;
          cout<<"s"<<s<<endl;
          cout<<"base"<<base<<endl;
          multiplosDivisor[i] = multi.multiplicar(numeroDois,s,base);
          
        }
        else
        {
          string s(1,intToChar(i));
          multiplosDivisor[i] = multi.multiplicar(numeroDois,s,base);
        }
      
      }
      string resto="";
      string quociente="";

      while(resto[0] != 48)
      {
      i =0;
      while(algarismoSignificativos.length()<numeroDois.length())
      {
        cout<<"gyebydu3nidmemd3o    "<< algarismoSignificativos.length()<<endl;
        //cout<<"jajajajabdwbhdbhwbhd"<<endl;
        algarismoSignificativos = algarismoSignificativos+numeroUm[i];  
        i++;
      }
    
    string a =sub.subtrair(algarismoSignificativos,numeroDois,base);
   /* cout<<"batatao :"<<algarismoSignificativos<<endl;
    cout<<"olha o corno aq-> :"<<numeroDois<<endl;
    cout<<"resultzknsk :"<<a<<endl;
    cout<<"length 1 :"<<algarismoSignificativos.length()<<endl;
    cout<<"length 2 :"<<numeroDois.length()<<endl;
    */
      if(sub.subtrair(algarismoSignificativos,numeroDois,base)[0]==45)
        algarismoSignificativos= algarismoSignificativos +numeroUm[++i];

      for(int y=0;y<base;y++)
      {
      //  cout<<algarismoSignificativos<<endl;
        resto = sub.subtrair(algarismoSignificativos,multiplosDivisor[y],base);
        //cout<<"jeej "<<resto<<endl; 
     
     
      if((char)(resto[0]) != 45) 
        {
         // cout<<"SALVE"<<endl;
              
          maiorMultiplo = multiplosDivisor[y];
        }
        else
          break;
      }

         
      quociente = quociente+ maiorMultiplo;
      }


      return quociente;
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
};
