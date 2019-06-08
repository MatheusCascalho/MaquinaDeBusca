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

void ListDocumentos::operator+(string Documento){
    documentos_.find(Documento)->second++;
}

bool ListDocumentos::operator<<(ListDocumentos X){
    if (this->documentos_.size() << X.documentos_.size()){
        return 1;
    }
    return 0;
}

void ListDocumentos::insert(string X){
    this->documentos_.insert(pair<string,int>(X,1));
}