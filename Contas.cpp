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

  }

  string Multiplicacao(){
    Multiplicador multiplicacao;
    string resultado = multiplicacao.multiplicar(numeroUm, numeroDois, base);
    return resultado;

  }

  string Divisao(){
    Divisor divisao;
    string resultado = divisao.dividir(numeroUm, numeroDois, base);
    return resultado;
    
  }

};