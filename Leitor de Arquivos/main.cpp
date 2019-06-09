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

    cout << "Testando a criacao e leitura de um indice: " << endl;

    

    Indice meuIndice(meuDiretorio);
    meuIndice.imprimirIndiceCompleto();

    system("pause");
    return 0;
}
