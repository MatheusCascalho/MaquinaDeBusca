#ifndef INDICE_H
#define INDICE_H

#include <string>
#include <map>
#include <set>
#include "palavra.h"

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

        // testa se p pertence ao índice
        bool pertence(const Palavra& p); 

        // retorna a quandidade de arquivo em que a palavra aparece
        // PRECONDIÇÃO: A palavra deve pertencer ao conjunto
        int arquivos(const Palavra& p);

        // Retorna o primeiro elemento de um indice.
        // PRECONDICAO: o indice nao pode estar vazio.
        string primeiro() const;

        // Adiciona uma palavra ao índice, bem como o conjunto de documentos em que ela aparece
        void adiciona(const Palavra& p);

        // retona todas as palavras do vocabulário
        std::set<Palavra> vocabulario();

        // Compara de *this tem os mesmos elementos de x.
        //bool operator==(const Indice& x) const;

        // Faz com que *this tenha os mesmos elementos de x.
        //void operator=(const Indice& x);

        // Desaloca a memoria de um indice.
        //~Indice();

    private:
        // palavra-chave 
        Palavra chave_;

        //conjunto de arquivos em que a palavra chave aparece
        std::set<Palavra> arquivos_;
        
        // Ponteiro do sentinela de um indice.
        //NoLeitor* fim_;

        // Numero de elementos de um indice.
        //int tam_;
};

#endif // INDICE_H