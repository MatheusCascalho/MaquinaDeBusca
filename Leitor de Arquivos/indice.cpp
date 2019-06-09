#include "indice.h"
#include <iostream>
#include <fstream>

using std::fstream;
using std::cout;
using std::endl;
using std::pair;

void Indice::criarIndice(Diretorio dir){
    fstream arquivoDoSumario;

    acharArquivos(dir, this->todosDocumentos_);

    for(string arquivoLido : todosDocumentos_){
        dir.setNome(arquivoLido);
        dir.concatenarEndereco();

        fstream File;
        File.open(dir.lerNomeCompleto());
        string Elemento;
        while(File >> Elemento){         
            transformaString(Elemento);
            ListDocumentos novo;
            novo.insert(dir.lerNome());
            if (this->elementos_.find(Elemento) == this->elementos_.end()){ //Quando um elemento nao pertence
                this->elementos_.insert(pair<string,ListDocumentos>(Elemento,novo));     //ao Map, .find retorna .end.
            } else {
                this->elementos_.find(Elemento)->second.insert(dir.lerNome());
            }
        }
    }
}

Indice::Indice(){

}

Indice::Indice(Diretorio dir){
    this->criarIndice(dir);
}

void Indice::imprimirIndice() const{
    //Ainda vou implementar.
}

void Indice::transformaString(string& valor){
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

int Indice::aparicoesTotal(string Palavra) const{
    //Ainda vou implementar
return 0;
}

map<string, ListDocumentos> Indice::getIndice() const{
    return this->elementos_;
}

int Indice::qtdDocs(){
    return todosDocumentos_.size();
}

/*
void imprimirIndice(const map<string,int> Map){
    if(Map.begin()==Map.end())cout<<"O indice invertido fornecido esta vazio";
    for (auto ListDocumentos=Map.begin();ListDocumentos!=Map.end();ListDocumentos++){
        cout <<"Palavra: ["<<ListDocumentos->first
             <<"] - Quantidade de repeticoes: ["<< ListDocumentos->second << "].\n" << endl;
    }
}
*/