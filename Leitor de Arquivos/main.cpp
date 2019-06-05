#include "indice.h"
#include <fstream>
#include <iostream>

using namespace std;

void imprimirList(const list<string> lista){
    for (string E : lista){
        cout << E << endl;
    }
}

int main(){

    cout << "Bem vindo ao leitor de Arquivos" << endl;

    string nomeSaida = "Saida.txt";
    cout << "NomeSaida: " << nomeSaida << endl;

    Diretorio meuDiretorio;
    cout << "Nome: " << meuDiretorio.lerNome() << endl
         << "Endereco: " << meuDiretorio.lerEndereco() << endl
         << "Nome Completo: " << meuDiretorio.lerNomeCompleto() << endl;

    list<string> arquivosPLer;
    acharArquivosPadrao(arquivosPLer);
    imprimirList(arquivosPLer);


    lerArquivos(meuDiretorio, arquivosPLer, nomeSaida);

    cout << "O arquivo Saida.txt deve ter sido preenchido." << endl;


    map<string,int> indiceInvertido;
    criarIndice(meuDiretorio, indiceInvertido);

    cout << "O indice invertido criado a partir do Sumario deve ter sido preenchido." << endl
         << "Imprimindo termo a termo:" << endl;
    imprimirIndice(indiceInvertido);

    return 0;
}
