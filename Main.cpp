#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;
#include "Contas.h"


int verificar(string numero, int tamanho, int base)  // verificar se está de acordo com a base informada
{
  int indice;
  for(indice = 0; indice < tamanho; indice++)  // percorrer toda a string
  {
    if(isalpha(numero[indice]))  // se o caractere atual não for um dígito
    {
      if((toupper(numero[indice])-55) > base - 1)
        return -1;  // não está de acordo
    }
    else if (isdigit(numero[indice]))  // se for um dígito
    {
      if((numero[indice]-48) > base - 1)
        return -1;  // não está de acordo
    }
    else 
    {
      if(numero[indice] == '.' || numero[indice] == ',' || numero[indice] == '-')
        continue;
      return -1;
    }
  }
  return 1;  // está de acordo
}


int main()
{
  int base;
  string priValor;  // o primeiro valor
  string secValor;  // o segunbdo valor
  char operacao;  // a base dos numeros informados

  cout<< "Digite a base entre 2 e 36 a qual deseja realizar operações: "<< endl;
  cin >> base;

  cout<< "Digite o primeiro valor: "<<endl;
  cin >> priValor;

  cout<< "Digite o segundo valor: "<<endl;
  cin >> secValor;

  int a =verificar(priValor,priValor.length(),base);  // verificar o primeiro numero
  int b =verificar(secValor,secValor.length(),base);  // verificar o segundo numero
  if (a < 0 || b < 0){  // se algum deles estiver incorreto
    cout<<"Os números informados não condizem com a base"<<endl;
    return 0;
  }

  Contas contas(priValor, secValor, base);  // objeto da classe Contas

  cout<<"Digite a operação dentre a lista: + - * / "<<endl;
  cin >> operacao;

  switch(operacao)
  {
    case'+':cout<<"+";
    cout<<"Resultado: " + contas.Soma()<<endl;  // escrever soma dos números
    break;

    case'-':cout<<"-\n";
    cout<<"Resultado: " + contas.Subtracao()<<endl;  // escrever subtração dos números
    break;

    case'*':cout<<"*\n";
    cout<<"Resultado: " + contas.Multiplicacao()<<endl; // escrever multiplicação dos números
    break;

    case'/':cout<<"/\n";
    cout<<"Resultado: " + contas.Divisao()<<endl;  // escrever divisão dos números
    break;

    default:cout<<"Digite uma operacao valida!"<<endl;

  }

  return 0;
}
