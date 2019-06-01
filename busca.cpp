#include <string>
#include <map>
#include <vector>
#include <math.h>
#include "Leitor de Arquivos/indice.h"
#include "busca.h"

using namespace BUSCA;

expressao_busca::expressao_busca(string e){
    tf_ = 0;
    idf_ = 0;
    exp_ = e;
}

string expressao_busca::expBusca(){
    return exp_;
}

std::vector<Palavra> expressao_busca::palavrasExpBusca(){
    ////////////////VOLTAR PARA FAZER!!!!!!
}
double expressao_busca::idf(){
    return idf_;
}

double expressao_busca::tf(){
    return tf_;
}

double expressao_busca::calculaIdf(Palavra p, diretorio c, Indice i){
    int n = c.qtdDocs();
    int nt = i.tamanho();

    idf_ = log(n/nt);

    return idf_;
}

double expressao_busca::normalizaTf(Indice i, Palavra p){
    double tfn = tf_ / i.arquivos(p);
    return tfn;
}

double expressao_busca::determinaW(Documento d, Palavra p, Indice i, diretorio c){
    //w = tf * idf
    double w = this->normalizaTf(i, p) * this->calculaIdf(p, c, i);
    return w;
}

///INCOMPLETO!!!!!!!!!!!!!!!
double ranking::similaridade(Documento d, expressao_busca q, Indice i, diretorio c){
    double den = 0;
    for(int t = 0; t < q.palavrasExpBusca().size(); t++){
        //INCOMPLETO!!!!
        double prod = q.determinaW(d, q.palavrasExpBusca()[t], i, c);
    }
}