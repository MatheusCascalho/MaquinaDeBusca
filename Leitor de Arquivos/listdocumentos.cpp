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

int ListDocumentos::numTotal(string Palavra) const{
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
    return *(documentos_.find(Documento));
}

void ListDocumentos::inserir(string Documento){
    this->documentos_.insert(pair<string,int>(Documento,1));
}

void ListDocumentos::incrementar(string Documento){
    cout << "incrementando documento. Antes: " << this->documentos_.find(Documento)->second;
    this->documentos_.find(Documento)->second++;
    cout << " - Depois: " << this->documentos_.find(Documento)->second << std::endl;
}