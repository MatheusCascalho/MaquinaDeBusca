#ifndef DIRETORIO_H
#define DIRETORIO_H

#include <string>

using std::string;

class Diretorio{
    public:
        //Construtor de um Diretorio Padrao.
        Diretorio();

        //Construtor de um Diretorio com um Endereco e um Nome.
        Diretorio(string Endereco, string Nome);

        //Retorna o Nome que esta gravado em um Diretorio selecionado.
        string lerNome() const;

        //Retorna o nome do Endereco que esta gravado no Diretorio selecionado.
        string lerEndereco() const;

        //Retorna o Nome Completo do Diretorio selecionado.
        string lerNomeCompleto() const;

        //Faz com que Palavra seja o novo Nome do Diretorio selecionado.
        void setNome(string Palavra);

        //Faz com que Palavra seja o novo Endereco do Diretorio selecionado.
        void setEndereco(string Palavra);

        //Use esta funcao para concatenar Nome e Endereco de um diretorio, gerando um Nome Completo.
        void concatenarEndereco();

    private:
        //O Endereco do diretorio onde esta localizado o arquivo (Conta a partir do diretorio onde esta localizado este executavel).
        string prefixo_;

        //Nome do arquivo gravado em um Diretorio.
        string nomeArquivo_;

        //Caminho composto por Endereco e Nome de um arquivo.
        string nomeCompleto_;
};

#endif // DIRETORIO_H