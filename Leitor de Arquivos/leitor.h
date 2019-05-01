/* Aqui vao ser declarados todas as funcoes relacionadas ao leitor de arquivos da primeira tarefa.

O objetivo e criar um Leitor que consegue abrir todos os arquivos .txt de um diretorio, armazenar
em forma de strings todas as palavras destes arquivos, assim como o numero de vezes em que elas aparecem
e por fim gerar um Indice Invertido contendo cada um dos valores armazenados, retirando sinais de pontuacao
e ignorando Maiusculas e Minusculas.  */ 

#ifndef LEITOR_H
#define LEITOR_H

#include <string>

struct NoLeitor;

class Indice {
    public:
        // Cria um indice invertido vazio.
        Indice();

        // Cria um indice com os mesmos elementos de x.
        Indice(const Indice& x);

        // Testa se um indice esta vazio.
        bool vazio() const;

        // Retorna o numero de elementos de um indice.
        int tamanho() const;

        // Retorna o primeiro elemento de um indice.
        // PRECONDICAO: o indice nao pode estar vazio.
        string primeiro() const;

        // Compara de *this tem os mesmos elementos de x.
        bool operator==(const Indice& x) const;

        // Faz com que *this tenha os mesmos elementos de x.
        void operator=(const Indice& x);

        // Desaloca a memoria de um indice.
        ~Indice();

    private:
        // Ponteiro do sentinela de um indice.
        NoLeitor* fim_;

        // Numero de elementos de um indice.
        int tam_;
};

class Leitor {
    public:

    private:
};


#endif // LEITOR_H