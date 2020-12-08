#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
#include <stdlib.h>
#include <math.h>
using std::string;

class Subtrador{

  public:
    static string subtrair(string numeroUm, string numeroDois, int base)
    {
      return getSubtracao(numeroUm, numeroDois, base);
    }

  private:
    static string getSubtracao(string numeroUm, string numeroDois, int base)
    {

    }

    static int charToInt(char letter)
    {
      return (int) (letter - 55);
    }

    static char intToChar(int number)
    {
      return (char) (number + 55);
    }

};