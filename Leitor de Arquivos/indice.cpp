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
        int i = 1;
        while(File >> Elemento){        
            transformaString(Elemento);
            cout << i << "  " << Elemento << endl;;
            i++; 
            if (this->elementos_.find(Elemento) == this->elementos_.end()){ //Quando um elemento nao pertence
                pair<string, ListDocumentos> Par;                           //ao Map, .find retorna .end.
                Par.first = Elemento;                
                Par.second.inserir(arquivoLido); //chamando funcao insert de listdocumentos. 
                elementos_.insert(Par);           
            } else {
                if (this->elementos_.find(Elemento)->first == arquivoLido){
                    this->elementos_.find(Elemento)->second.operator+(arquivoLido); //Localiza o par pela chave Elemento e incrementa o int.
                } else {
                    pair<string, ListDocumentos> Par;
                    Par.first = Elemento;
                    Par.second.inserir(arquivoLido);
                    elementos_.insert(Par);
                }
            }
        }
        File.close();    
    }
}

Indice::Indice(){

}

Indice::Indice(Diretorio dir){
    this->criarIndice(dir);
}

void Indice::imprimirIndiceCompleto() const{
    cout << "Iniciando Processo de impressao completa do Indice Invertido." << endl
         << "Imprimindo todos os documentos usados na criacao desse Indice Invertido:" <<endl;

    int i = 1;
    for (string Documento : this->todosDocumentos_){
        cout << i << "- [" << Documento << "] " << endl;
        i++;
    }

    cout << "Confirme para imprimir todas as palavras coletadas no indice" << endl
         << "Assim como todos os documentos onde cada palavra aparece" << endl
         << "Seguidos do numero de aparicoes em cada um destes documentos" << endl;

    system("pause");
    for (pair<string, ListDocumentos> Par : this->elementos_){
        cout << "[" << Par.first << "] / ";
        list <string> Documentos = Par.second.retornaLista();
        for (string Documento : Documentos){
            cout << "--- ["<< Documento << "] - [" << Par.second.lerOcorrencias(Documento) << "]";
        }
        cout << endl;
    }

    cout << "Indice Invertido foi impresso com sucesso!" << endl;

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

list<string> Indice::getTodosDocumentos() const{
    return this->todosDocumentos_;
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