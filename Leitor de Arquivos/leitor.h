#ifndef LEITOR_H
#define LEITOR_H

#include "diretorio.h"
#include <list>
#include <fstream>

using std::list;

//Recebe um arquivo e uma lista, lendo uma string e adicionando-a na lista.
//void lerUmString(fstream arquivo, list<string>& lista);

//Recebe uma lista vazia e a preenche com todos os nomes de arquivos 
//encontrados no sumario do construtor padrao de Diretorio.
void acharArquivosPadrao(list<string>& lista);

//PRECONDICAO: O diretorio deve ter a variavel privada nomeCompleto != de um valor nulo.
//Recebe um diretorio com o endereco do sumario e uma lista vazia, preenchendo-a com os nomes de arquivos lidos.
void acharArquivos(Diretorio sumario, list<string>& lista);

//Recebe o local onde estao os arquivos, uma lista com o nome destes arquivos e cria um novo 
//arquivo com o nome fornecido para preenche-lo com todas as palavras lidas de todos os arquivos da lista.
void lerArquivos(Diretorio local, list<string>& arquivosPLer, string nome);

#endif //LEITOR_H