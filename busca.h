//REPRESENTAÇÃO DA EXPRESSÃO DE BUSCA E DO RANKING DE PALAVRAS
//As expressões de consultas realizadas nessa máquina de busca são representadas por vetores 
//que relacionam cada palavra aos seus respectivos pesos. Ou seja, cada posição do vetor representa o peso de uma 
//das n palavras do vocabulário utilizado.
//Requisitos para utilizar a classe: Representaçao de documentos, coleção de documentos e do índice invertido

#ifndef BUSCA_H
#define BUSCA_H

#include <string>
#include <map>
#include <vector>
#include <math.h>
#include "Leitor de Arquivos/indice.h"

namespace BUSCA
{
    class expressao_busca{
    public:
        //construtor
        expressao_busca(string e);

        //retorna a expressao de busca
        string expBusca();

        //retorna a expressao de busca como vetor
        std::vector<Palavra> palavrasExpBusca();
        
        //retorna idf
        double idf();

        //retorna a frequencia do termo
        double tf();

        //calcula o inverso da frequencia da palavra p nos documentos de um diretorio c
        double calculaIdf(Palavra p, diretorio c, Indice i);

        //Normaliza tf
        double normalizaTf(Indice i, Palavra p);

        //determina o peso de uma palavra P em um documento d
        double determinaW(Documento d, Palavra P, Indice i, diretorio c);
 
    private:
        //Frequencia do termo
        double tf_;
        //inverso da frequencia nos documento
        double idf_;

        //expressao propriamente dita
        string exp_;
    };

    class ranking{
        public:

            //retorna a similaridade entre um documento d e uma expressão de busca q (do tipo string)
            double similaridade(Documento d, expressao_busca q, Indice i, diretorio c);
       
            //Retorna o ranking de documentos
            std::map<Documento, Palavra> rankingCosseno();

            double funcaoHash(Palavra p, Documento d);

    };

} // namespace BUSCA


#endif //BUSCA_H