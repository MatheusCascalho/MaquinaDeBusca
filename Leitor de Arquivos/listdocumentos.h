#ifndef LISTDOCUMENTOS_H
#define LISTDOCUMENTOS_H

#include "leitor.h"
#include <map>
#include <iostream>

using std::map;

//Esta Classe ira guardar todos os documentos onde uma palavra aparece
//em um indice, assim como o numero de vezes que ela aparece em cada um destes documentos.

class ListDocumentos{
    public:
    //Construtor de um ListDocumentos vazio.
    ListDocumentos();

    //Retorna uma lista de arquivos nos quais uma Palavra aparece.
    list<string> retornaLista() const;

    //Retorna o numero de ocorrencias de uma Palavra em um Documento.
    int lerOcorrencias(string Documento) const;

    //Retorna o numero total de ocorrencias de uma Palavra em todos os documentos que ela aparece.
    int numTotal() const;

    //Imprime na tela uma lista de documentos com suas correspondentes aparicoes.
    void imprimeListDoc();
 
    //Operador que incrementa o numero de ocorrencias de uma Palavra em um Documento.
    //PRECONDICAO: A Palavra deve ter aparecido pelo menos 1 vez nesse Documento.
    void operator+(string Documento);

    //Operador << para implementar ListDocumentos em Indice, compara com X pelo numero absoluto de palavras armazenadas.
    bool operator<<(ListDocumentos x);

    //Insere uma nova aparicao de uma Palavra em um Documento especifico.
    //PRECONDICAO: A Palavra nao pode ter aparecido nenhuma vez nesse Documento.
    void insert(string Documento);

    private:

    //Registra em cada um dos documentos o numero de aparicoes da Palavra.
    map<string, int> documentos_;

};


#endif //LISTDOCUMENTOS_H