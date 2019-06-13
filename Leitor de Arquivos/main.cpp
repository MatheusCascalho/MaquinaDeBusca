#include "indice.h"
#include "busca.h"
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

    string expressaoBusca;
    cout << "Digite uma expressao de busca: " << endl;
    cin >> expressaoBusca;

    Busca q(expressaoBusca, meuIndice);
    map<double, string> resposta = q.rankingCosseno(meuIndice);
    cout << "A pesquisa retornou" << resposta.size() <<"Documentos. Documentos relacionados: " << endl;
    map<double, string>::iterator it;
    for (it = resposta.begin(); it != resposta.end(); it++){
          cout << it->second << endl;
    }
    cout << "FIM DA PESQUISA" << endl;    

    system("pause");
    return 0;
}
