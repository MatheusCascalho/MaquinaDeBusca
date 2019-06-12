<<<<<<< HEAD
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <list>
#include <math.h>
#include "indice.h"
#include "busca.h"
#include "listdocumentos.h"

using std::string;
using std::map;

Busca::Busca(){
    exp_ = ' ';
}
Busca::Busca(string e, Indice i){
    exp_ = e;

    int primeiraLetra = 0; //posição da primeira letra de uma palavra
    string palavra;
    for (int i = 0; i < strlen(e.c_str()); i++){
        if ((e[i]==' ')||(e[i]=='.')||(e[i]==',')||(e[i]=='?')){
            palavra = e.substr(primeiraLetra, i - 1);
            transformaString(palavra); //normaliza a palavra
            vetExp_.push_back(palavra); //armazena a palavra no vetor
            primeiraLetra = i + 1; //primeira letra da próxima palavra
        }
    }

    for (string palavra: vetExp_){
        if ((i.getIndice().count(palavra)) == 0) i.inserir(palavra, "expressao");
        else if (i.getIndice().count(palavra) != 0) i.incrementar(palavra, "expressao");
    }
}

string Busca::expBusca(){
    return exp_;
}

std::vector<string> Busca::palavrasExpBusca(){
    return vetExp_;
}

double Busca::tf(string p){
    int tf = 0;
    transformaString(p);
    for (int i = 0; i < vetExp_.size(); i++){
        if (vetExp_[i] == p) tf++;
    }
    return tf;
}

double Busca::tfmax(Indice i){
    double tfmax = 0;
    std::map<string, ListDocumentos> ind = i.getIndice();
    std::map<string, ListDocumentos>::iterator it;
    for(it = ind.begin(); it != ind.end(); it++){
        map<string, int>::iterator itInterno;
        ListDocumentos l = it->second;
        map<string, int> documentos = l.getDocs();
        for (itInterno = documentos.begin(); itInterno != documentos.end(); itInterno++){
            if (itInterno->second > tfmax) tfmax = itInterno->second;
        }
    }

    return tfmax;
}

double Busca::idf(string p, Indice i){
    transformaString(p);
    int qtdDocs = i.getTodosDocumentos().size();
    int ondePOcorre = i.getIndice().find(p)->second.retornaLista().size();

    double idf = log2(qtdDocs/ondePOcorre);

    return idf;
}

std::map<string, double> Busca::coordenadaDocsNaPalavra(Indice i, string p)
{
    transformaString(p); //normaliza a palavra
    double freqMax = this->tfmax(i); //encontra a frequencia máxima que uma palavra qualquer pode admitir
    double importanciaDaPalavra = this->idf(p, i); //importancia da palavra p para qualquer documento
    
    std::map<string, double> coordenadasDocs;

    std::map<string, int>::iterator it;
    ListDocumentos l = i.getIndice().find(p)->second;
    std::map<string, int> docsNaPalavra = l.getDocs();
    for(it = docsNaPalavra.begin(); it != docsNaPalavra.end(); it++){
        string nomeDoArquivo = it->first;
        double tf = it->second/freqMax;
        double w = tf * importanciaDaPalavra;
        coordenadasDocs[nomeDoArquivo] = w;
    }
    return coordenadasDocs; 
    
   
}


double Busca::similaridade(Indice i, string doc){
    double num = 0; 
    double coordenadaDocumento = 0, coordenadaExpressao = 0;
    double den_fr1 = 0, den_fr2 = 0;

    for(string palavra : this->palavrasExpBusca()){
        coordenadaDocumento = this->coordenadaDocsNaPalavra(i, palavra).find(doc)->second;
        coordenadaExpressao = this->coordenadaDocsNaPalavra(i, palavra).find("expressao")->second;
                
        double prod = coordenadaDocumento * coordenadaExpressao; 
        
        num = num + prod;
        den_fr1 = den_fr1 + coordenadaDocumento;
        den_fr2 = den_fr2 + coordenadaExpressao;
    }

    double den = sqrt(den_fr1 * den_fr1) * sqrt(den_fr2 * den_fr2);

    return num/den;
}

std::map<double, string> Busca::rankingCosseno(Indice i){
    std::map<double, string> ranking;
    list<string> docs = i.getTodosDocumentos();
    for (string arquivo : docs){
        double pos = this->similaridade(i, arquivo);
        ranking[pos] = arquivo;
    }

    return ranking;
}


=======
#include <string.h>
#include <vector>
#include <math.h>
#include "indice.h"
#include "busca.h"

using std::string;
using std::map;

Busca::Busca(){
    exp_ = ' ';
}
Busca::Busca(string e, Indice i){
    exp_ = e;

    int primeiraLetra = 0; //posição da primeira letra de uma palavra
    string palavra;
    for (int i = 0; i < strlen(e.c_str()); i++){
        if ((e[i]==' ')||(e[i]=='.')||(e[i]==',')||(e[i]=='?')){
            palavra = e.substr(primeiraLetra, i - 1);
            transformaString(palavra); //normaliza a palavra
            vetExp_.push_back(palavra); //armazena a palavra no vetor
            primeiraLetra = i + 1; //primeira letra da próxima palavra
        }
    }

    for (string palavra: vetExp_){
        if ((i.getIndice().count(palavra)) == 0) i.inserir(palavra, "expressao");
        else if (i.getIndice().count(palavra) != 0) i.incrementar(palavra, "expressao");
    }
}

string Busca::expBusca(){
    return exp_;
}

std::vector<string> Busca::palavrasExpBusca(){
    return vetExp_;
}

double Busca::tf(string p){
    int tf = 0;
    transformaString(p);
    for (int i = 0; i < vetExp_.size(); i++){
        if (vetExp_[i] == p) tf++;
    }
    return tf;
}

double Busca::tfmax(Indice i){
    double tfmax = 0;
    std::map<string, ListDocumentos> ind = i.getIndice();
    std::map<string, ListDocumentos>::iterator it;
    for(it = ind.begin(); it != ind.end(); it++){
        map<string, int>::iterator itInterno;
        map<string, int> documentos = it->second.getDocs();
        for (itInterno = documentos.begin(); itInterno != documentos.end(); itInterno++){
            if (itInterno->second > tfmax) tfmax = itInterno->second;
        }
    }

    return tfmax;
}

double Busca::idf(string p, Indice i){
    transformaString(p);
    int qtdDocs = i.getTodosDocumentos().size();
    int ondePOcorre = i.getIndice().find(p)->second.retornaLista().size();

    double idf = log2(qtdDocs/ondePOcorre);

    return idf;
}

std::map<string, double> Busca::coordenadaDocsNaPalavra(Indice i, string p)
{
    transformaString(p); //normaliza a palavra
    double freqMax = this->tfmax(i); //encontra a frequencia máxima que uma palavra qualquer pode admitir
    double importanciaDaPalavra = this->idf(p, i); //importancia da palavra p para qualquer documento
    
    std::map<string, double> coordenadasDocs;

    std::map<string, int>::iterator it;
    std::map<string, int> docsNaPalavra = i.getIndice().find(p)->second.getDocs();
    for(it = docsNaPalavra.begin(); it != docsNaPalavra.end(); it++){
        string nomeDoArquivo = it->first;
        double tf = it->second/freqMax;
        double w = tf * importanciaDaPalavra;
        coordenadasDocs[nomeDoArquivo] = w;
    }
    return coordenadasDocs; 
    
   
}


double Busca::similaridade(Indice i, string doc){
    double num = 0; 
    double coordenadaDocumento = 0, coordenadaExpressao = 0;
    double den_fr1 = 0, den_fr2 = 0;

    for(string palavra : this->palavrasExpBusca()){
        coordenadaDocumento = this->coordenadaDocsNaPalavra(i, palavra).find(doc)->second;
        coordenadaExpressao = this->coordenadaDocsNaPalavra(i, palavra).find("expressao")->second;
                
        double prod = coordenadaDocumento * coordenadaExpressao; 
        
        num = num + prod;
        den_fr1 = den_fr1 + coordenadaDocumento;
        den_fr2 = den_fr2 + coordenadaExpressao;
    }

    double den = sqrt(den_fr1 * den_fr1) * sqrt(den_fr2 * den_fr2);

    return num/den;
}

std::map<double, string> Busca::rankingCosseno(Indice i){
    std::map<double, string> ranking;
    list<string> docs = i.getTodosDocumentos();
    for (string arquivo : docs){
        double pos = this->similaridade(i, arquivo);
        ranking[pos] = arquivo;
    }

    return ranking;
}
>>>>>>> 83334e719fea46e0e4419d8a922bea3a13f99457
