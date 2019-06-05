/* Aqui estao declaradas as ferramentas necessarias para gerar um Indice Invertido.

Isto sera realizado primeiramente pelo void LerArquivos, que recebe o endereco
de um diretorio e e capazde abri-lo, ler todos os arquivos .txt e armazenar suas
palavras no indice.
O struct Palavra sera responsavel pela formatacao dos textos,
Ja a classe Indice e aquela que ira armazenar todos os dados e montar o indice
invertido propriamente dito.  */ 

#ifndef INDICE_H
#define INDICE_H

#include "leitor.h"
#include <map>

using std::map;

//Este struct ira guardar o numero de ocorrencias de um elemento e uma lista dos arquivos onde ele aparece.
class Aux{
    public:
    //Construtor de um Aux vazio.
    Aux();

    //Construtor de um Aux especifico, com I numero de ocorrencias e uma lista A de aparicoes.
    Aux(int I, list<string> A);

    //Retorna a lista de arquivos do Aux.
    list<string> retornaLista() const;

    //Retorna o numero de ocorrencias em um Aux.
    int lerOcorrencias() const;

    //Operador que incrementa o numero de ocorrencias em um Aux.
    void operator++();

    //Operator que soma o numero de ocorrencias de dois Aux.
    Aux operator+(Aux x);

    //Operador << para implementar aux em map.
    bool operator<<(Aux x);

    //Insere uma aparicao.
    void inserirAparicao(string X);

    private:

    //Registra o numero de ocorrencias de uma palavra em um map.
    int numeroDeOcorrencias_;

    //Registra o nome dos arquivos onde certa palavra foi encontrada.
    list<string> aparicoes_;

};

//Ferramenta que padroniza um string (Maiuscula -> minuscula, Pontuacao-Sinais-> ' ' )
void transformaString(string& valor);

//Cria um indice a partir de um endereco de um arquivo Sumario e um map<string,int>.
void criarIndice(Diretorio meuDiretorio, map<string,int>& indiceInvertido);

//Cria um indice a partir de um endereco de um unico arquivo.
void criarIndiceUnico(Diretorio endereco, map<string,int>& indiceInvertido);

//Recebe um indice inverttido do tipo map<string,int> e imprime na tela.
void imprimirIndice(const map<string,int> Map);

#endif // INDICE_H