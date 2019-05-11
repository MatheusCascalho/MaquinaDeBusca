/* Aqui vao ser declarados todas as funcoes relacionadas ao leitor de arquivos da primeira tarefa.

O objetivo e criar um Leitor que consegue abrir todos os arquivos .txt de um diretorio, armazenar
em forma de strings todas as palavras destes arquivos, assim como o numero de vezes em que elas aparecem
e por fim gerar um Indice Invertido contendo cada um dos valores armazenados, retirando sinais de pontuacao
e ignorando Maiusculas e Minusculas.  */ 

#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <map>
#include <set>
#include "indice.h"
#include "palavra.h"

class Leitor {
    public:
        //Convertr maiúsculas em minusculas e apaga acentuação
        void padronizaLetra();

    private:
};


#endif // LEITOR_H
