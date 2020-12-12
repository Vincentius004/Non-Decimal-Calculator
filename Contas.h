#ifndef CONTAS_H
#define CONTAS_H
#include<iostream>
#include <string>

using std::string;

    class Contas
    {
        
    public:
        Contas(string um,string dois,int b);
        string Subtracao();
        string Multiplicacao();
        string Divisao();
        string Soma();
    
    private:
        string numeroUm, numeroDois;
        int base;
    };

#endif
