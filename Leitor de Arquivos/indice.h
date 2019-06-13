// Aqui estao declaradas as ferramentas necessarias para gerar um Indice Invertido.

#ifndef INDICE_H
#define INDICE_H

#include "leitor.h"
#include "listdocumentos.h"
#include <map>

using std::map;

class Indice{
    public:
    //Cria um Indice Invertido vazio.
    Indice();

    //Cria um Indice Invertido a partir de um e um Diretorio fornecido.
    Indice(Diretorio meuDiretorio);

    //Preenche um Indice Invertido a partir de um Diretorio do Sumario fornecido.
    void criarIndice(Diretorio meuDiretorio);

    //Imprime o Indice Invertido na Tela com todas as suas Palavras,
    //os Documentos onde cada uma das Palavras aparece e seu respectivo Numero de Aparicoes em cada um deles.
    void imprimirIndiceCompleto() const;

    //Retorna o Numero de Aparicoes de uma Palavra em um Documento fornecido.
    int aparicoesDoc(string Elemento, string Documento);

    //Retorna a Soma Total de Aparicoes de uma Palavra em todos os Documentos que ela aparece.
    int aparicoesTotal(string Palavra) const;

    //Retorna o par<string,int> especifico de um Documento com seu numero de Aparicoes de dentro da Lista de Elementos.
    pair<string,int> acharDoc(string Elemento, string Documento);

    //Retorna o map com os Elementos de um indice invertido.
    //PRECONDICAO: o Indice Invertido nao pode estar vazio.
    map<string, ListDocumentos> getIndice() const;

    //Insere um novo Elemento na Lista de Palavras de um Indice Invertido.
    void inserir(string Elemento, string Documento);

    //Incrementa o Numero de Aparicoes de um Documento para um Elemento especifico do Indice Invertido.
    void incrementar(string Elemento, string Documento);

    //Adiciona na Lista de Aparicoes de Documentos de uma Palavra do Indice Invertido um novo Documento.
    void inserirDoc(string Elemento, string Documento);

    //Retorna todos os documentos usados para formar um Indice Invertido especifico.
    //Precondicao: O indice nao pode estar vazio.
    list<string> getTodosDocumentos() const; 

    private:
    //Map<string, ListDocumentos> que forma o indice invertido.
    map<string, ListDocumentos> elementos_;

    //Lista com todos os documentos usados para formar este indice.
    list<string> todosDocumentos_;

    //Insere um novo Elemento na Lista de Palavras de um Indice Invertido de maneira com que ele nao apareca em 
    //nenhum dos documentos do indice.
    //Esta funcao so e usada para evitar bugs com Indice::acharDoc(string Elemento, string Documento) no caso da palavra nao
    //Estar presente no Indice, e o map do mesmo retornar um endereco NULL.
    void inserirVazio(string Elemento);
};

#endif // INDICE_H