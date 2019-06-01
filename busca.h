//REPRESENTAÇÃO DA EXPRESSÃO DE BUSCA
//As expressões de consultas realizadas nessa máquina de busca são representadas por vetores 
//que relacionam cada palavra aos seus respectivos pesos. Ou seja, cada posição do vetor representa o peso de uma 
//das n palavras do vocabulário utilizado.

#ifndef BUSCA_H
#define BUSCA_H

#include <string>
#include <map>
#include "Leitor de Arquivos/indice.h"

class busca{
    public:
        //construtor
        busca();
        
        //retorna idf
        double idf();

        //retorna a frequencia do termo
        double tf();

        //calcula o inverso da frequencia nos documentos
        double calculaIdf();

        //Normaliza tf
        double normalizaTf();

        //determina o peso de uma palavra P em um documento d
        double determinaW(Documento d, Palavra P);

        //retorna a similaridade entre um documento d e uma expressão de busca q
        double similaridade(Documento d, string q);
        
        //Retorna o ranking de documentos
        std::map<Documento, Palavra> rankingCosseno();

        double funcaoHash(Palavra p, Documento d);

    private:
        //Frequencia do termo
        double tf_;
        //inverso da frequencia nos documento
        double idf_;
};

#endif //BUSCA_H