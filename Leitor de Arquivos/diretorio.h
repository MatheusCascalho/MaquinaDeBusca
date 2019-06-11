#ifndef DIRETORIO_H
#define DIRETORIO_H

#include <string>

using std::string;

class Diretorio{
    public:
        //Construtor de um diretorio padrao.
        Diretorio();

        //Construtor de um diretorio com endereco E e nome de arquivo N.
        Diretorio(string E, string N);

        //Retorna o nome do arquivo selecionado.
        string lerNome() const;

        //Retorna o endereco selecionado.
        string lerEndereco() const;

        //Retorna o nome completo do Diretorio.
        string lerNomeCompleto() const;

        //Faz com que S seja o novo nome do arquivo.
        void setNome(string S);

        //Faz com que S seja o novo endereco do arquivo.
        void setEndereco(string S);

        //Use esta funcao para contatenar o prefixo com o nome do arquivo.
        void concatenarEndereco();

    private:
        //O endereco do diretorio do arquivo (Conta a partir do diretorio onde esta localizado este executavel).
        string prefixo_;

        //Nome do arquivo que sera lido.
        string nomeArquivo_;

        //Caminho composto por endereco e nome do arquivo.
        string nomeCompleto_;
};

#endif // DIRETORIO_H