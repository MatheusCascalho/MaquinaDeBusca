#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <list>
#include <math.h>
#include "Leitor de Arquivos/indice.h"
#include "busca.h"

using namespace BUSCA;

expressao_busca::expressao_busca(string e){
    exp_ = e;

    int primeiraLetra = 0; //posição da primeira letra de uma palavra
    string palavra;
    for (int i = 0; i < strlen(e); i++){
        if (e[i]==' '){
            palavra = e.substr(primeiraLetra, i - 1);
            transformaString(palavra); //normaliza a palavra
            vetExp_.push_back(palavra); //armazena a palavra no vetor
            primeiraLetra = i + 1; //primeira letra da próxima palavra
        }
    }
}

string expressao_busca::expBusca(){
    return exp_;
}

std::vector<Palavra> expressao_busca::palavrasExpBusca(){
    return vetExp_;
}

double expressao_busca::tf(string p){
    int tf = 0;
    transformaString(p);
    for (int i = 0; i < vetExp_.size(); i++){
        if (vetExp_[i] == p) tf++;
    }

    return tf;
}

double expressao_busca::idf(string p, Indice i){
    
}

double ranking::coordenadaDocsNaPalavra(ListDocumentos ldocs, string p)
{
    //w = tf * idf
    double tf = tf_/i.arquivos(p);
    double w = tf * this->idf(p, c, i);
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