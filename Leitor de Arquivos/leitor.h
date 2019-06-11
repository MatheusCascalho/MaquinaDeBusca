#ifndef LEITOR_H
#define LEITOR_H

#include "diretorio.h"
#include <list>
#include <fstream>

using std::list;

//Recebe uma Lista Vazia e a preenche com todos os Nomes de Arquivos encontrados no Sumario do Construtor Padrao de Diretorio.
void acharArquivosPadrao(list<string>& lista);

//Recebe um Diretorio com o Endereco do Sumario e uma lista vazia, preenchendo-a com os Nomes de Arquivos lidos.
//PRECONDICAO: O Diretorio deve ter a variavel privada nomeCompleto != de um valor nulo.
void acharArquivos(Diretorio sumario, list<string>& lista);

//Recebe o Diretorio onde localizam-se arquivos, uma Lista com o nome dos arquivos a serem lidos e um Nome de Arquivo,
//Esta funcao vai ler todos as palavras em todos os arquivos, e grava-las em um Novo Arquivo criado que tem como nome o Nome de Arquivo fornecido.
void lerArquivos(Diretorio local, list<string>& arquivosPLer, string nome);

//Ferramenta que padroniza um string para o modelo necessario para um Indice. (Maiuscula -> minuscula, Pontuacao-Sinais-> ' ')
void transformaString(string& valor);

#endif //LEITOR_H