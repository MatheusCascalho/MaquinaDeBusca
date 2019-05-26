//#include "indice.h"
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <cctype>
#include <set>

using namespace std;

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

struct Diretorio{
    /* O Prefixo deve ser nomeado com qualquer pasta a frente de onde e executado o programa. Terminando
    no diretorio onde esta presente o Arquivo Guia.*/
    string Prefixo = "Diretorio\\\\";

    /*Nome do Arquivo guia, com extencao .txt ele deve ter o nome de todos os arquivos a serem lidos*/
    string nomeArquivo = "Sumario.txt";

    /*Use esta funcao para abrir os arquivos corretamente*/
    string nomeCompleto;

    /*Esta funcao deve ser chamada sempre que o nome do arquivo e declarado ou alterado.*/
    void definirNome(){
        nomeCompleto = Prefixo + nomeArquivo;
    }
};

void imprimirIndice(const map<string,int> Map){
    if(Map.begin()==Map.end())cout<<"O indice invertido fornecido esta vazio";
    for (auto aux=Map.begin();aux!=Map.end();aux++){
        cout <<"Palavra: ["<<aux->first
             <<"] - Quantidade de repeticoes: ["<< aux->second << "].\n" << endl;
    }
}

void imprimirList(const list<string> lista){
    for (string E : lista){
        cout << E << endl;
    }
}

void acharArquivos(list<string>& arquivosPLer, const Diretorio meuDiretorio){
    fstream Arquivo;
    string PalavraLida;
    //precondicao: o diretorio deve estar com o nome correto apos a funcao .definirNome do struct Diretorio.
    Arquivo.open(meuDiretorio.nomeCompleto);
    while (Arquivo >> PalavraLida){
        arquivosPLer.push_back(PalavraLida);
    }
    if (arquivosPLer.empty()){ //Se o numero de palavras lidas foi zero, o diretorio nao encontrou arquivos.
        cerr << "Nenhum arquivo encontrado no diretorio selecionado!" << endl;
    }
}

void lerArquivos(list<string>& listaDeArquivos, Diretorio meuDiretorio, map<string,int>& indiceInvertido){
    if (listaDeArquivos.empty()){
        cerr << "A lista fornecida ao leitor de arquivos esta vazia!" << endl;
    }
    for (string E : listaDeArquivos){
        fstream Arquivo;
        meuDiretorio.nomeArquivo = E;
        meuDiretorio.definirNome();
        Arquivo.open(meuDiretorio.nomeCompleto);

        string elemento;
        //Procura o termo no indice invertido. Caso não encontre, o insere o elemento no índice. Caso encontre, aumenta o valor de repetições
        while (Arquivo >> elemento){
                transformaString(elemento);
                if(indiceInvertido.find(elemento) == indiceInvertido.end()){ //map.find retorna um iterator pro map.end()
                    indiceInvertido.insert(pair<string,int>(elemento,1));
                }
                else{
                    map<string,int>::iterator iteraT=indiceInvertido.find(elemento);
                    int n = iteraT->second;
                    indiceInvertido.erase(elemento);
                    indiceInvertido.insert(pair<string,int>(elemento,n+1));
                }
            }
    }
}

int main(){
    Diretorio meuDiretorio;
    list<string> arquivosPLer;
    map<string,int> indiceInvertido;//A string é a palavra e o int é a quantidade de repetições :)

    cout << "Bem vindo ao leitor de arquivos!" << endl;

    meuDiretorio.definirNome(); // Junta o prefixo com o nome do arquivo

    cout  << "Abrindo o seguinte Sumario encontrado no endereco:" << endl
          << meuDiretorio.nomeCompleto << endl;
    system("pause");
    cout  << "Nomes de arquivos encontrados no Arquivo Guia que foi fornecido pelo diretorio:" << endl;

    acharArquivos(arquivosPLer, meuDiretorio);
    imprimirList(arquivosPLer);


    system("pause");
    cout << "Iniciando leitura dos arquivos e gerando um indice invertido: " << endl;

    lerArquivos(arquivosPLer, meuDiretorio, indiceInvertido);

    cout << "O seu indice invertido foi gerado. Imprimindo termo a termo:" << endl;
    imprimirIndice(indiceInvertido);
    system("pause");
    

    return 0;
}
