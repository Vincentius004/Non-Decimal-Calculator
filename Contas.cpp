#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
using std::string;
#include "Somador.cpp"
#include "Subtrador.cpp"
#include "Multiplicador.cpp"
#include "Divisor.cpp"

class Contas{

  string numeroUm, numeroDois;
  int base;

  public:
    Contas(string um, string dois, int b){
      numeroUm = um;
      numeroDois = dois;
      base = b;
    }

  string Soma(){
    Somador soma;
    string resultado =  soma.somar(numeroUm, numeroDois, base);
    return resultado;
  }

  string Subtracao(){
    Subtrador subtracao;
    string resultado = subtracao.subtrair(numeroUm, numeroDois, base);
    return resultado;
    return "1.0";
  }

  string Multiplicacao(){
    //string resultado = Multiplicador::multiplicar(numeroUm, numeroDois, base);
    //return Multiplicador.multiplicar(numeroUm, numeroDois, base);
    return "2.0";
  }

  string Divisao(){
    //string resultado = Divisora::dividir(numeroUm, numeroDois, base);
    //return resultado;
    return "3.0";
  }

};