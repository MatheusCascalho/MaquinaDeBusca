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

    //Imprime o Indice Invertido na Tela com todos os seus elementos.
    void imprimirIndiceCompleto() const;

    //Faz com que uma string seja Normalizada no padrao do Indice Invertido.
    void transformaString(string& Palavra);

    //retorna as aparicoes de uma palavra em um documento.
    int aparicoesDoc(string Elemento, string Documento);

    //retorna a soma de aparicoes de uma palavra em todos os documentos que ela aparece.
    int aparicoesTotal(string Palavra) const;

    //retorna o par especifico de um Documento com seu numero de aparicoes de dentro da Lista de Elementos.
    pair<string,int> acharDoc(string Elemento, string Documento);

    //Retorna o indice invertido.
    //PRECONDICAO: o indice nao pode estar vazio.
    map<string, ListDocumentos> getIndice() const;

    //Insere um novo Elemento na lista de palavras.
    void inserir(string Elemento, string Documento);

    //Incrementa uma aparicao de um Documento para um Elemento especifico.
    void incrementar(string Elemento, string Documento);

    //Adiciona na lista de aparicoes de uma Palavra um novo Documento.
    void inserirDoc(string Elemento, string Documento);

    //Retorna todos os documentos usados para formar o Indice Invertido.
    //Precondicao: O indice nao pode estar vazio.
    list<string> getTodosDocumentos() const; 

    private:
    //Map<string, ListDocumentos> que forma o indice invertido.
    map<string, ListDocumentos> elementos_;

    //Lista com todos os documentos usados para formar este indice.
    list<string> todosDocumentos_;
};

//Ferramenta que padroniza um string (Maiuscula -> minuscula, Pontuacao-Sinais-> ' ')
void transformaString(string& valor);

#endif // INDICE_H