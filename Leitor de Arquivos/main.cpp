#include "indice.h"
#include <fstream>
#include <iostream>
#include "busca.h"

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




    cout << "O arquivo Saida.txt deve ter sido preenchido." << endl;

    cout << "Testando a criacao e leitura de um indice: " << endl;

    

    Indice meuIndice(meuDiretorio);
    meuIndice.imprimirIndiceCompleto();

    cout << "Testando leitor de um arquivo:" << endl;

    list<string> palavras;
    meuDiretorio.setNome("bruno.txt");
    meuDiretorio.concatenarEndereco();
    cout << "Lendo todas as palavras de [" << meuDiretorio.lerNomeCompleto() << "]" << endl;;
    lerUmArquivo(meuDiretorio, palavras);
    imprimirList(palavras);

    string pergunta;
    cout << "Digite uma palavra para saber quantas vezes ela apareceu em todos os documentos: " << endl;
    cin >> pergunta;
    cout << "A palavra ["  << pergunta << "] apareceu um total de [" 
         << meuIndice.aparicoesTotal(pergunta) << "] vezes no seu Indice Invertido." << endl;

    system("pause");
    return 0;
}
