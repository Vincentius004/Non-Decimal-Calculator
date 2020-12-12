#ifndef MULTIPLICADOR_H
#define MULTIPLICADOR_H
#include <iostream>
#include<string>
#include <stdlib.h>
#include <math.h>
using std::string;

class Multiplicador{
    
    public:
    string multiplicar(string numeroUm, string numeroDois, int base);
    
    private:
    string primeiro;
    string segundo;
    bool primeiroNegativo = false;
    bool segundoNegativo = false;
    int casasVirgula1;
    int casasVirgula2;
    string getMultiplicacao(string numeroUm, string numeroDois, int base);
    int charToInt(char letter);
    char intToChar(int number);
    void ajeitarStrings(string numeroUm, string numeroDois);
};

#endif