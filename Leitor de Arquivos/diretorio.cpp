#include "diretorio.h"

Diretorio::Diretorio(){
    prefixo_ = "Diretorio\\\\";
    nomeArquivo_ = "Sumario.txt";
    concatenarEndereco();
}

Diretorio::Diretorio(string E, string N){
    prefixo_ = E;
    nomeArquivo_ = N;
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

void Diretorio::setNome(string S){
    nomeArquivo_ = S;
}

void Diretorio::setEndereco(string S){
    prefixo_ = S;
}

void Diretorio::concatenarEndereco(){
    nomeCompleto_ = prefixo_ + nomeArquivo_;
}