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
      return getDivisao(primeiro, segundo, base);
      
    }

  private:
  string primeiro, segundo;
  int casasVirgula1 = 0;
  int casasVirgula2 = 0;

    string getDivisao(string numeroUm,string numeroDois,int base)
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
        if(std::stod(resto) == 0)
        {
          resultado += i;
          break;
        }
        else
        {
          resultado += i;
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
      return resultado;
      //break;

    /*  Multiplicador multi;
      Subtrador sub;
      string multiplosDivisor[base];
      string maiorMultiplo="";
      string algarismoSignificativos="";
      bool primeiraVez = true;

      numeroUm = numeroUm+"0";
      numeroDois = numeroDois+"0";

    int i = 0;

      for( i=0;i<base;i++)
      {
        
        if(i <10)
        {
          string s(1,i+'0');
          multiplosDivisor[i] = multi.multiplicar(numeroDois,s,base);
          
        }
        else
        {
          string s(1,intToChar(i));
          multiplosDivisor[i] = multi.multiplicar(numeroDois,s,base);
        }
          cout<<multiplosDivisor[i]<<endl;
      }
      string resto="";
      string quociente="";

      
      i =0;


      int aux =numeroUm.length()-numeroDois.length();
      if(numeroDois.length()>aux)
      {

        while(algarismoSignificativos.length()<numeroDois.length()-aux)
        {
        if(i<numeroUm.length()){        algarismoSignificativos = algarismoSignificativos+numeroUm[i];     
         
        i++;
        }
        else
        break;
        }
      }
      else
      {
         while(algarismoSignificativos.length()<numeroDois.length()-aux-1)
        {
        if(i<numeroUm.length()){
        algarismoSignificativos = algarismoSignificativos+numeroUm[i];      
        i++;
        }
        else
        break;
        }
        
      }
      
      algarismoSignificativos = algarismoSignificativos+"0";
      i++;
      
        string a =sub.subtrair(algarismoSignificativos,numeroDois,base);


    
      if((char)a[0]==45){
        if(i<numeroUm.length() && (char)numeroUm[i]!=48){
          algarismoSignificativos= algarismoSignificativos +numeroUm[i];
          quociente = quociente+"0.";
        }
        else if((char)numeroUm[i]==48)
        {
          while(algarismoSignificativos.length()<numeroDois.length())
          algarismoSignificativos= algarismoSignificativos+"0";

           
          
         
        }
        else
        {
          while(algarismoSignificativos.length()<numeroDois.length())
          algarismoSignificativos= algarismoSignificativos+"0";

          
        }
      }
      
      while((char)resto[0]!=48)
      {

      int y;
      for(y=0;y<base;y++)
      {
        
        cout<<"Y "<<y<<" Multiplos= "<<multiplosDivisor[y]<<endl;
        resto = sub.subtrair(algarismoSignificativos,multiplosDivisor[y],base);

        cout<<"olha o resto aq OH->>>"<<resto<<endl;
        cout<<"algarismoSignificativos"<<algarismoSignificativos.length()<<endl;
        cout<<"olha o multiplosDivisor aq OH->>>"<<multiplosDivisor[y]<<endl;
        system("pause");
        cout<<"\n";
        
     
     
      if((char)(resto[0]) != 45) 
        {
          
          maiorMultiplo = multiplosDivisor[y];
        }
        else
        {
          resto = sub.subtrair(algarismoSignificativos,multiplosDivisor[y-1],base);
         //cout<<"resto:"<<resto<<endl;
          break;
        }

        cout<<"Y: "<<y<<endl;
      }
        
      if(primeiraVez)
      {
      
      if(y<10)
      {
      if(y<1)
      {
        cout<<"Olha q legal"<<endl;
        primeiraVez= false;
        quociente = quociente+"0.";
      
      }
      else if(y!=1)
      {
      cout<<"\nwtf1: "<<quociente<<endl;
      quociente = quociente + (char)(y+47);    
      cout<<"\nwtf2: "<<quociente<<endl;
      }
      }
      else if(y<base)
      {
         cout<<"\nwtf3: "<<quociente<<endl;
        quociente=quociente+(char)(y+54);
         cout<<"\nwtf4: "<<quociente<<endl;
      }
      
      
      }
      else
      {
        if(y<10)
        {
        if(y>0)
        quociente = quociente + (char)(y+47); 
        else
        {
        cout<<"hmmm"<<endl;
       // if(quociente.length()<2)
         // quociente= quociente+".";
        //quociente= quociente+"0";
        }
        }
        else if(y<base)
        {
          
        quociente = quociente +(char)(y+54);
        }
        
      }
      

      
      algarismoSignificativos =  resto;
      i++;
      if(i<numeroUm.length() && (char)numeroUm[i]!=48){
          algarismoSignificativos= algarismoSignificativos +numeroUm[i];
          cout<<" Entrei aq oh"<<algarismoSignificativos<<endl;
        }
        else if((char)numeroUm[i]==48)
        {
          while(algarismoSignificativos.length()<numeroDois.length())
          algarismoSignificativos= algarismoSignificativos+"0";
        }
        else if(i==numeroUm.length())
        {

          algarismoSignificativos= algarismoSignificativos+"0";
          if(primeiraVez)
          {
            primeiraVez=false;
            cout<<"cagou aq"<<quociente<<endl;
            quociente=quociente+".";
          }
        }
      cout<<"Quociente"<<quociente<<endl;
      if(quociente.length() > 10)
      break;

      }


      return quociente;
      */
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
