#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;


int verificar(string numero, int tamanho, int base)  // verificar se está de acordo com a base informada
{
  int indice;
  for(indice = 0; indice < tamanho; indice++)  // percorrer toda a string
  {
    if(!isdigit(numero[indice]))  // se o caractere atual não for um dígito
    {
      if((toupper(numero[indice])-55) > base - 1)
        return -1;  // não está de acordo
      }
    else  // se for um dígito
    {
      if((numero[indice]-48) > base - 1)
        return -1;  // não está de acordo
    }
  }
  return 1;  // está de acordo
}


int main()
{
  int base;
  string priValor;
  string secValor;
  char operacao;

  cout<< "Digite a base entre 2 e 36 a qual deseja realizar operações: "<< endl;
  cin >> base;

  cout<< "Digite o primeiro valor: "<<endl;
  cin >> priValor;

  cout<< "Digite o segundo valor: "<<endl;
  cin >> secValor;



  int a =verificar(secValor,secValor.length(),base);
  cout<<a<<endl;

  cout<<"Digite a operação dentre a lista: + - * / "<<endl;
  cin >> operacao;

  switch(operacao)
  {
    case'+':cout<<"+";
    break;

    case'-':cout<<"-";
    break;

    case'*':cout<<"*";
    break;

    case'/':cout<<"/";

    default:cout<<"Digite uma operacao valida!"<<endl;

  }

  return 0;
}