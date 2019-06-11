//REPRESENTAÇÃO DA EXPRESSÃO DE BUSCA E DO RANKING DE PALAVRAS
//As expressões de consultas realizadas nessa máquina de busca são representadas por vetores 
//que relacionam cada palavra aos seus respectivos pesos. Ou seja, cada posição do vetor representa o peso de uma 
//das n palavras do vocabulário utilizado.
//Requisitos para utilizar a classe: Representaçao de documentos, coleção de documentos e do índice invertido

#ifndef BUSCA_H
#define BUSCA_H

#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <list>
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
        std::vector<string> palavrasExpBusca();
        
        //retorna a frequencia da palavra p na expressão de busca
        double tf(string p);

        //frequencia máxima de qualquer termo dentro do índice
        double tfmax(Indice i);

        //calcula o inverso da frequencia da palavra p nos documentos de um índice invertido i
        double idf(string p, Indice i);

        //determina o peso de um documento no eixo p. w(d, p)
        double coordenadaDocsNaPalavra(Indice i, string p);


 
    protected:
        //Frequencia do termo
        //MUDAR ISSO PARA A CLASSE PALAVRA
        //double tf_;

        //inverso da frequencia nos documento
        //MUDAR ISSO PARA A CLASSE PALAVRA
        //double idf_;

        //expressao propriamente dita
        string exp_;

        //representação da expressão de busca como um vetor
        //IMPLEMENTAR!!!!
        std::vector<string> vetExp_;

        friend class teste;

    };

    class ranking{
        public:
            //construtor
            ranking();

            //retorna a similaridade entre um documento d e uma expressão de busca q (do tipo string)
            //double similaridade(Documento d, expressao_busca q, Indice i, diretorio c);
            double similaridade(expressao_busca q, Indice i, Diretorio c);
       
            //Retorna o ranking de documentos
            std::map<double, string> rankingCosseno(Diretorio c, expressao_busca q, Indice i);

            //Mapa de coordenadas. Representa uma tabela onde temos os documentos e expressões de busca
            //nas colunas e as palavras do vocabulário nas linhas. Cada celula da tabela representa a o peso de uma 
            //paralavra em um documento
            std::map<string, std::vector<double>>  mapaCoordenada(Indice i);
        private:
            //ordenação dos documentos
            std::vector<string> ordemDocumentos_;
    };

} // namespace BUSCA


#endif //BUSCA_H