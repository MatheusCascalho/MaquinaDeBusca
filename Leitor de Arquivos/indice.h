// Aqui estao declaradas as ferramentas necessarias para gerar um Indice Invertido.

#ifndef INDICE_H
#define INDICE_H

#include "leitor.h"
#include "listdocumentos.h"
#include <map>

using std::map;


class Indice{
    public:
    //Cria um indice invertido vazio.
    Indice();

    //Cria um indice a partir de um e um diretorio.
    Indice(Diretorio dir);

    //Gera um indice invertido a partir de um diretorio.
    void criarIndice(Diretorio dir);

    //Imprime o Indice Invertido na Tela.
    void imprimirIndice() const;

    //Faz com que uma string seja Normalizada no padrao do Indice Invertido.
    void transformaString(string& Palavra);

    //retorna a soma de aparicoes de uma palavra em todos os documentos que ela aparece.
    int aparicoesTotal(string Palavra) const;

    //Retorna o indice invertido.
    //PRECONDICAO: o indice nao pode estar vazio.
    map<string, ListDocumentos> getIndice() const;

    private:
    //Map<string, ListDocumentos> que forma o indice invertido.
    map<string, ListDocumentos> elementos_;

    //Lista com todos os documentos usados para formar este indice.
    list<string> todosDocumentos_;
};

//Ferramenta que padroniza um string (Maiuscula -> minuscula, Pontuacao-Sinais-> ' ')
void transformaString(string& valor);

#endif // INDICE_H