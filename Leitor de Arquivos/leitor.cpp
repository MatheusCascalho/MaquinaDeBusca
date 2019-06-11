#include "leitor.h"
#include <iostream>
#include <fstream>

using std::cerr;
using std::fstream;
using std::ofstream;
using std::endl;

/*void lerUmString(fstream arquivo, list<string>& lista){
    string Elemento;
    arquivo >> Elemento;
    lista.push_back(Elemento);
}*/


void transformaString(string& valor){
    for (int i = 0; i < valor.size(); i++){
        valor[i] = tolower(valor[i]);

        if(!(isalpha(valor[i])) ){
            if (i == 0){
                valor = string(valor, i+1, valor.size() - 1);
                i--;
            } else if (i == valor.size() -1){
                valor = string(valor, 0, valor.size() - 1);
                i = i-2; //a subtracao por 2 leva em conta o argumento de +1 do proximo ciclo.
            } else {
                valor[i] = ' ';
            }
        }
    }
}

void acharArquivosPadrao(list<string>& lista){
    Diretorio padrao;
    fstream Arquivo;
    string PalavraLida;
    Arquivo.open(padrao.lerNomeCompleto());
    while (Arquivo >> PalavraLida){
        lista.push_back(PalavraLida);
    }
    if (lista.empty()){ //Se o numero de palavras lidas foi zero, o diretorio nao encontrou arquivos.
        cerr << "Nenhum arquivo encontrado no diretorio padrao!" << endl;
    }
}

void acharArquivos(const Diretorio sumario, list<string>& lista){
    fstream Arquivo;
    string PalavraLida;
    //precondicao: o diretorio deve estar com o nome correto apos a funcao .definirNome do struct Diretorio.
    Arquivo.open(sumario.lerNomeCompleto());
    while (Arquivo >> PalavraLida){
        lista.push_back(PalavraLida);
    }
    if (lista.empty()){ //Se o numero de palavras lidas foi zero, o diretorio nao encontrou arquivos.
        cerr << "Nenhum arquivo encontrado no diretorio selecionado!" << endl;
    }
}

void lerUmArquivo(Diretorio endereco, list<string>& palavrasLidas){
    fstream Arquivo;
    Arquivo.open(endereco.lerNomeCompleto());
    string Palavra;
    while (Arquivo >> Palavra){
        transformaString(Palavra);
        palavrasLidas.push_back(Palavra);
    }
    Arquivo.close();
    if (palavrasLidas.size() == 0){
        cerr << "Nenhuma palavra foi lida" << endl;
    }
}

void lerArquivos(Diretorio local, list<string>& arquivosPLer, string nome){
    if (arquivosPLer.empty()){
        std::cout << "A lista de arquivos para ler fornecida esta vazia!";
    }

    local.setNome(nome); //Abrindo um arquivo com o endereco de um diretorio padrao e nome fornecido.
    local.concatenarEndereco();
    ofstream palavrasLidas(local.lerNomeCompleto());

    for (string S : arquivosPLer){
        fstream Arquivo;
        local.setNome(S);
        local.concatenarEndereco();
        Arquivo.open(local.lerNomeCompleto());

        string Elemento;
        int i = 0;
        while (Arquivo >> Elemento){
            palavrasLidas << Elemento << " ";
            if (!((i+1)%10)){  //Este pedaco so esta formatando a disposicao do texto.
                palavrasLidas << endl;
            }
            i++;
        }
        Arquivo.close();
    }
    palavrasLidas.close();
}


