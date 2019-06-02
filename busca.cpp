#include <string>
#include <map>
#include <vector>
#include <math.h>
#include "Leitor de Arquivos/indice.h"
#include "busca.h"

using namespace BUSCA;

expressao_busca::expressao_busca(string e){
    //tf_ = 0;
    //idf_ = 0;
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

double expressao_busca::determinaW(Palavra p, diretorio c, Indice i){
    //w = tf * idf
    double tf = tf_/i.arquivos(p);
    double w = tf * this->calculaIdf(p, c, i);
    return w;
}

ranking::ranking(){
    ///////////INCOMPLETO!!!!!!!!!!
}
double ranking::similaridade(Documento d, expressao_busca q, Indice i, diretorio c){
    double num = 0;
    double coordenadaDocumento = 0, coordenadaExpressao = 0;
    double den_fr1 = 0, den_fr2 = 0;

    for(int t = 0; t < q.palavrasExpBusca().size(); t++){
        coordenadaDocumento = d.determinaW(q.palavrasExpBusca()[t], c, i);
        coordenadaExpressao = q.determinaW(q.palavrasExpBusca()[t], c, i);
                
        double prod = coordenadaDocumento * coordenadaExpressao; 
        
        num = num + prod;
        den_fr1 = den_fr1 + coordenadaDocumento;
        den_fr2 = den_fr2 + coordenadaExpressao;
    }

    double den = sqrt(den_fr1 * den_fr1) * sqrt(den_fr2 * den_fr2);

    return num/den;
}

std::map<double, Documento> ranking::rankingCosseno(diretorio c, expressao_busca q, Indice ind){
    std::map<double, Documento> r;
    for (int i = 0; i < c.qtdDocs(); i++){
        double chave = this->similaridade(c.docs()[i], q, ind, c);
        r[chave] = c.docs()[i];
    }
    return r;
}

double ranking::funcaoHash(Palavra p, Documento d, Indice i){

}