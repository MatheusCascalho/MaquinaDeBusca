#include "indice.h"
#include <iostream>
#include <fstream>

using std::fstream;
using std::cout;
using std::endl;
using std::pair;

Indice::Indice(){
    //Propositalmente nao faz nada. para preencher o Indice use criarIndice().
}

Indice::Indice(Diretorio dir){
    this->criarIndice(dir);
}

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
            if (this->elementos_.find(Elemento) == this->elementos_.end()){ //Quando um elemento nao pertence a lista.
                cout << "[" << Elemento << "] Nao pertence a lista de elementos, inserindo... " << endl;
                this->inserir(Elemento, arquivoLido); 
                cout << "[" << Elemento << "] Inserido com sucesso." << endl;          
            } else {
                if (this->elementos_.find(Elemento)->first == Elemento){ //Se na lista de palavras esta palavra ja apareceu uma vez.
                    cout << "[" << Elemento << "] Ja apareceu na lista, verificando arquivo... " << endl;
                    if(this->acharDoc(Elemento, arquivoLido).second != 0){ //Se esta palavra ja apareceu no Arquivo que esta aberto.
                        cout << "[" << Elemento << "] Ja apareceu " << this->aparicoesDoc(Elemento, arquivoLido) << " vezes em " << arquivoLido
                             << endl << "Incrementando aparicoes..." << endl;
                        this->incrementar(Elemento, arquivoLido); 
                        cout << "Numero de aparicoes de [" << Elemento << "] em [" << arquivoLido << "] incrementado com sucesso." << endl;
                    } else {// Se esta palavra apareceu neste Arquivo pela primeira vez.
                        cout << "[" << Elemento << "] Ainda nao apareceu nenhuma vez em [" << arquivoLido << "]... inserindo..." << endl;
                        this->incrementar(Elemento, arquivoLido);
                        cout << "Foi registrado que [" << Elemento << "] apareceu pela primeira vez em [" << arquivoLido << "]" << endl;
                    }
                }
            }
        }
        File.close();    
    }
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
            cout << "\t--- ["<< Documento << "] - [" << Par.second.lerOcorrencias(Documento) << "]";
        }
        cout << endl;
    }

    cout << "Indice Invertido foi impresso com sucesso!" << endl;

}


int Indice::aparicoesDoc(string Elemento, string Documento){
    return this->elementos_.find(Elemento)->second.lerOcorrencias(Documento);
}

int Indice::aparicoesTotal(string Palavra) const{
    //Ainda vou implementar
return 0;
}

void Indice::inserir(string Elemento, string Documento){
    pair<string, ListDocumentos> Par;
    Par.first = Elemento;
    Par.second.inserir(Documento);
    elementos_.insert(Par);
}

void Indice::incrementar(string Elemento, string Documento){
    this->elementos_.find(Elemento)->second.incrementar(Documento);
}

void Indice::inserirDoc(string Elemento, string Documento){
    this->elementos_.find(Elemento)->second.inserir(Documento);
}

pair<string, int> Indice::acharDoc(string Elemento, string Documento){
    return (this->elementos_.find(Elemento)->second.acharDoc(Documento));
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