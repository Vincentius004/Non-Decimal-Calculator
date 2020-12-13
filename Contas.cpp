#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
using std::string;
#include "Contas.h"
#include "Somador.h"
#include "Subtrador.h"
#include "Multiplicador.h"
#include "Divisor.h"

    Contas::Contas(string um, string dois, int b){  // construtor da classe
      numeroUm = um;
      numeroDois = dois;
      base = b;
    }

  string Contas::Soma(){  // retorna a soma dos numeros
    Somador soma;
    string resultado =  soma.somar(numeroUm, numeroDois, base);
    return resultado;
  }

  string Contas::Subtracao(){  // retorna a subtração dos numeros
    Subtrador subtracao;
    string resultado = subtracao.subtrair(numeroUm, numeroDois, base);
    return resultado;

  }

  string Contas::Multiplicacao(){  // retorna a multiplicação dos numeros
    Multiplicador multiplicacao;
    string resultado = multiplicacao.multiplicar(numeroUm, numeroDois, base);
    return resultado;

  }

  string Contas::Divisao(){  // retorna a divisão do numeros
    Divisor divisao;
    string resultado = divisao.dividir(numeroUm, numeroDois, base);
    return resultado;
    
  }
