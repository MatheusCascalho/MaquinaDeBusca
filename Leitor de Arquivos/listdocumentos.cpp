#include "listdocumentos.h"

using std::pair;
using std::cout;
using std::pair;

ListDocumentos::ListDocumentos(){
}

list<string> ListDocumentos::retornaLista() const{
    list<string> doc;
    for (auto Aux = documentos_.begin(); Aux != documentos_.end(); Aux++){
       doc.push_back(Aux->first);
    }
    return doc;
}

int ListDocumentos::lerOcorrencias(string Documento) const{
    int ocorrencias = documentos_.find(Documento)->second;
    return ocorrencias;
}

int ListDocumentos::numTotal() const{
    int soma = 0;
    for(pair<string,int> No : documentos_){
        soma += No.second;
    }
    return soma;
}

bool ListDocumentos::operator<<(ListDocumentos X){
    if (this->documentos_.size() << X.documentos_.size()){
        return 1;
    }
    return 0;
}

pair <string,int> ListDocumentos::acharDoc(string Documento){
    if (this->documentos_.find(Documento) != this->documentos_.end()){ //So vai retornar o par se este documento ja apareceu.
        return *(this->documentos_.find(Documento));
    } else { //Ira inserir este novo documento antes de retornar o seu par, por razoes de erro em caso de .find(Documento) nao achar nada.
        this->documentos_.insert(pair<string,int>(Documento,0)); //Esta inclusao faz com que o numero de aparicoes seja 0, por razoes de teste.
        return *(this->documentos_.find(Documento));
    }
    //Logo, ao usar a funcao acharDoc(string Documento), um par<string,int> correspondente sempre existe em documentos_
    //ja que em caso negativo um novo par e inserido. A unica diferenca e que apos o uso do metodo acharDoc, um documento
    //que nao apareceu nenhuma vez tem como numero de aparicoes 0 por default gracas a este metodo.
}

map<string, int> ListDocumentos::getDocs(){
    return this->documentos_;
}

void ListDocumentos::inserir(string Documento){
    this->documentos_.insert(pair<string,int>(Documento,1));
}

void ListDocumentos::incrementar(string Documento){
    this->documentos_.find(Documento)->second++;
}