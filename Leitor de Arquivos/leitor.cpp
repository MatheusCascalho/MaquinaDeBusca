/* Aqui e onde sera realizada a implementacao das funcoes do arquivo leitor.h */

#include "leitor.h"

using std::string;

struct NoLeitor {
    string valor;
    NoLeitor* esq;
    NoLeitor* dir;
    int num;

    NoLeitor(){
        esq = dir = nullptr;
        num = 0;
    }

    NoLeitor(string s, NoLeitor* e, NoLeitor* d){
        valor = s;
        esq = e;
        dir = d;
        num++;
    }
};