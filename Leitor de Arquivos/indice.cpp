#include "indice.h"
#include <iostream>
#include <fstream>

using std::fstream;
using std::cout;
using std::endl;
using std::pair;

Aux::Aux(){
    numeroDeOcorrencias_ = 0;
}

Aux::Aux(int I, list<string> A){
    numeroDeOcorrencias_ = I;
    for (string E : A){
        aparicoes_.push_back(E);
    }
}

list<string> Aux::retornaLista() const{
    return aparicoes_;
}

int Aux::lerOcorrencias() const{
    return numeroDeOcorrencias_;
}

void Aux::operator++(){
    numeroDeOcorrencias_++;
}

Aux Aux::operator+(Aux X){
    int numeroTotal = numeroDeOcorrencias_ + X.lerOcorrencias();
    Aux Fim(numeroTotal, aparicoes_);
    return Fim;
}

bool Aux::operator<<(Aux X){
    int numero = numeroDeOcorrencias_;
    if (numero << X.lerOcorrencias()){
        return true;
    }
    return false;
}

void Aux::inserirAparicao(string X){
    aparicoes_.push_back(X);
}


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


void criarIndice(Diretorio meuDiretorio, map<string,int>& indiceInvertido){
    list<string> arquivosPLer;
    fstream arquivoDoSumario;

    acharArquivos(meuDiretorio, arquivosPLer);

    for(string arquivoLido : arquivosPLer){
        meuDiretorio.setNome(arquivoLido);
        meuDiretorio.concatenarEndereco();

        fstream File;
        File.open(meuDiretorio.lerNomeCompleto());
        string Elemento;
        while(File >> Elemento){
            transformaString(Elemento);
            if (indiceInvertido.find(Elemento) == indiceInvertido.end()){ //Quando um elemento nao pertence
                indiceInvertido.insert(pair<string,int>(Elemento,1));     //ao Map, .find retorna .end.
            } else {
                indiceInvertido.find(Elemento)->second++;
            }
        }
    }
}

void criarIndiceUnico(Diretorio endereco, map<string,int>& indiceInvertido){

}

void imprimirIndice(const map<string,int> Map){
    if(Map.begin()==Map.end())cout<<"O indice invertido fornecido esta vazio";
    for (auto aux=Map.begin();aux!=Map.end();aux++){
        cout <<"Palavra: ["<<aux->first
             <<"] - Quantidade de repeticoes: ["<< aux->second << "].\n" << endl;
    }
}


