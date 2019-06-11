#include "diretorio.h"

Diretorio::Diretorio(){ //O construtor padrao de um Diretorio por default aponta para o Sumario.
    prefixo_ = "Diretorio\\\\";
    nomeArquivo_ = "Sumario.txt";
    concatenarEndereco();
}

Diretorio::Diretorio(string Endereco, string Nome){
    prefixo_ = Endereco;
    nomeArquivo_ = Nome;
    concatenarEndereco();
}

string Diretorio::lerNome() const{
    return nomeArquivo_;
}

string Diretorio::lerEndereco() const{
    return prefixo_;
}

string Diretorio::lerNomeCompleto() const{
    return nomeCompleto_;
}

void Diretorio::setNome(string Nome){
    nomeArquivo_ = Nome;
}

void Diretorio::setEndereco(string Endereco){
    prefixo_ = Endereco;
}

void Diretorio::concatenarEndereco(){
    nomeCompleto_ = prefixo_ + nomeArquivo_;
}