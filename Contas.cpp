#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
using std::string;

class Contas{

  double numeroUm, numeroDois;
  int base;

  public:
    Contas(string um, string dois, int b){
      numeroUm = std::stod(um);
      numeroDois = std::stod(dois);
      base = b;
    }

  double Soma(){
    //return Somador.somar(numeroUm, numeroDois, base);
    return 0.0;
  }

  double Subtracao(){
    //return Subtrador.subtrair(numeroUm, numeroDois, base);
    return 1.0;
  }

  double Multiplicacao(){
    //return Multiplicador.multiplicar(numeroUm, numeroDois, base);
    return 2.0;
  }

  double Divisao(){
    //return Divisora.dividir(numeroUm, numeroDois, base);
    return 3.0;
  }

};