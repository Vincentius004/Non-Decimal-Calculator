#ifndef SUBTRADOR_H
#define SUBTRADOR_H
#include <iostream>
#include<string>
#include <stdlib.h>
#include <math.h>
using std::string;
 extern string primeiro, segundo;
class Subtrador{
    
    public:
    string subtrair(string numeroUm, string numeroDois, int base);
    
    private:
    bool primeiroNegativo = false;
    bool segundoNegativo = false;
    string primeiro;
    string segundo;
    string getSubtracao(string numeroUm, string numeroDois, int base);
    int charToInt(char letter);
    char intToChar(int number);
    void ajeitarStrings(string numeroUm, string numeroDois);
};



#endif