//ListDocumentos e o objeto localizado dentro de um Indice Invertido, cada Palavra de um indice invertido
//e associada a um unico ListDocumentos.
#ifndef LISTDOCUMENTOS_H
#define LISTDOCUMENTOS_H

#include "leitor.h"
#include <map>
#include <iostream>

using std::map;
using std::pair;

//Esta Classe ira guardar todos os Documentos onde uma Palavra aparece em um Indice Invertido, 
//assim como o Numero de Aparicoes dela em cada um destes respectivos Documentos.

class ListDocumentos{
    public:
    //Construtor de um ListDocumentos vazio.
    ListDocumentos();

    //Retorna uma lista de arquivos nos quais uma Palavra aparece.
    list<string> retornaLista() const;

    //Retorna o numero de ocorrencias de uma Palavra em um Documento.
    int lerOcorrencias(string Documento) const;

    //Retorna o numero total de ocorrencias de uma Palavra em todos os documentos que ela aparece.
    //PRECONDICAO: a Palavra deve pertencer a lista.
    int numTotal() const;

    //Imprime na tela uma lista de documentos com suas correspondentes aparicoes.
    void imprimeListDoc();

    //Retorna um endereco de um par em documentos_, ou um endereco para documentos_.end() no caso negativo
    pair<string,int> acharDoc(string Documentos);
 
    //Operador que incrementa o numero de ocorrencias de uma Palavra em um Documento.
    //PRECONDICAO: A Palavra deve ter aparecido pelo menos 1 vez nesse Documento.
    void incrementar(string Documento);

    //Operador << para implementar ListDocumentos em Indice, compara com X pelo numero absoluto de palavras armazenadas.
    bool operator<<(ListDocumentos x);

    //Insere uma nova aparicao de uma Palavra em um Documento especifico.
    //PRECONDICAO: A Palavra nao pode ter aparecido nenhuma vez nesse Documento.
    void inserir(string Documento);

    //Retorna o map que guarda os documentos, assim como suas respectivas contagens de aparicao.
    map<string, int> getDocs();

    private:

    //Registra em cada um dos documentos o numero de aparicoes da Palavra.
    map<string, int> documentos_;

};


#endif //LISTDOCUMENTOS_H