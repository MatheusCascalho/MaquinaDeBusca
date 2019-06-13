#include "indice.h"
#include <iostream>
#include <fstream>

using std::fstream;
using std::cout;
using std::endl;
using std::pair;

Indice::Indice(){
    //Propositalmente nao faz nada. para preencher este Indice Invertido vazio use o metodo criarIndice(Diretorio meuDiretorio).
}

Indice::Indice(Diretorio meuDiretorio){
    this->criarIndice(meuDiretorio);
}

void Indice::criarIndice(Diretorio meuDiretorio){

    acharArquivos(meuDiretorio, this->todosDocumentos_);
    cout << "Iniciando processo de geracao do Indice Invertido a partir do endereco fornecido." << endl;
    system("pause");

    for(string arquivoLido : todosDocumentos_){  //Funcao se repete para cada um dos arquivos listados no Sumario fornecido pelo meuDiretorio.
        meuDiretorio.setNome(arquivoLido);
        meuDiretorio.concatenarEndereco();

        cout << "Abrindo arquivo [" << meuDiretorio.lerNome() << "]" << endl;
        fstream File;
        File.open(meuDiretorio.lerNomeCompleto());
        cout << "[" << meuDiretorio.lerNome() << "] foi aberto com sucesso, iniciando leitura de suas Palavras..." << endl;
        
        string Elemento;   
        while(File >> Elemento){                   
            transformaString(Elemento); //Normaliza as Palavras lidas.

            if (this->elementos_.find(Elemento) == this->elementos_.end()){ //Condicao que e verdadeira quando uma Palavra nao apareceu na Lista de Palavras do Indice.

                cout << "[" << Elemento << "] Nao pertence a lista de palavras, inserindo... " << endl;
                this->inserir(Elemento, arquivoLido); 
                cout << "[" << Elemento << "] Inserido com sucesso./n" << endl;

            } else if(this->elementos_.find(Elemento)->first == Elemento){ //Se na Lista de Palavras esta Palavra ja apareceu pelo menos uma vez.

                    cout << "[" << Elemento << "] Ja apareceu na lista, verificando arquivo... " << endl;

                    if(this->acharDoc(Elemento, arquivoLido).second != 0){ //Se esta Palavra ja apareceu no Arquivo que esta atualmente aberto por esta funcao.

                        cout << "[" << Elemento << "] Ja apareceu " << this->aparicoesDoc(Elemento, arquivoLido) << " vezes em " << arquivoLido
                             << endl << "Incrementando aparicoes..." << endl;
                        this->incrementar(Elemento, arquivoLido); 
                        cout << "Numero de aparicoes de [" << Elemento << "] em [" << arquivoLido << "] incrementado com sucesso." << endl;

                    } else {//Se esta Palavra acaba de aparecer no arquivo aberto por esta funcao pela primeira vez.

                        cout << "[" << Elemento << "] Ainda nao apareceu nenhuma vez em [" << arquivoLido << "]. inserindo..." << endl;
                        this->incrementar(Elemento, arquivoLido);
                        cout << "Foi registrado que [" << Elemento << "] apareceu pela primeira vez em [" << arquivoLido << "]" << endl;

                    }
            }
        }
        cout << "Leitura de [" << meuDiretorio.lerNome() << "] concluida com sucesso.\n" << endl;
        File.close();    
    }
    cout << "O Indice Invertido foi criado com sucesso!." << endl;
}

void Indice::imprimirIndiceCompleto() const{
    cout << "Iniciando Processo de impressao completa do Indice Invertido." << endl;
    system("pause");

    cout << "Imprimindo todos os documentos usados na criacao desse Indice Invertido:" <<endl;

    int i = 1;
    for (string Documento : this->todosDocumentos_){
        cout << i << "- [" << Documento << "] " << endl;
        i++;
    }

    cout << "Confirme para imprimir todas as palavras coletadas no indice" << endl
         << "Assim como todos os documentos onde cada palavra aparece" << endl
         << "Seguidos do numero de aparicoes em cada um destes documentos" << endl;

    system("pause");
    for (pair<string, ListDocumentos> Par : this->elementos_){ //Para cada uma das palavras do Indice.
        cout << "[" << Par.first << "] / ";
        list <string> Documentos = Par.second.retornaLista(); //Vai retornar uma lista com todos os Documentos associados a Palavra.
        for (string Documento : Documentos){ //Para cada um desses Documentos.
            cout << "\t--- ["<< Documento << "] - [" << Par.second.lerOcorrencias(Documento) << "]";
        }
        cout << endl;
    }

    cout << "Indice Invertido foi impresso com sucesso!" << endl;

}


int Indice::aparicoesDoc(string Elemento, string Documento){
    if(this->elementos_.find(Elemento) != this->elementos_.end()){
        return this->elementos_.find(Elemento)->second.lerOcorrencias(Documento);
    } else {
        return 0;
    }
}

int Indice::aparicoesTotal(string Palavra) const{
    if(this->elementos_.find(Palavra) != this->elementos_.end()){
        return this->elementos_.find(Palavra)->second.numTotal();
    } else {
        return 0;
    }
}

void Indice::inserir(string Elemento, string Documento){
    pair<string, ListDocumentos> Par;
    Par.first = Elemento;
    Par.second.inserir(Documento);
    this->elementos_.insert(Par);
}

void Indice::incrementar(string Elemento, string Documento){
    this->elementos_.find(Elemento)->second.incrementar(Documento);
}

void Indice::inserirDoc(string Elemento, string Documento){
    this->elementos_.find(Elemento)->second.inserir(Documento);
}

pair<string, int> Indice::acharDoc(string Elemento, string Documento){
    if(this->elementos_.find(Elemento) != elementos_.end()){
        return (this->elementos_.find(Elemento)->second.acharDoc(Documento));
    } else {
        this->inserirVazio(Elemento);
        return (this->elementos_.find(Elemento)->second.acharDoc(Documento));
    }
}

map<string, ListDocumentos> Indice::getIndice() const{
    return this->elementos_;
}

list<string> Indice::getTodosDocumentos() const{
    return this->todosDocumentos_;
}

void Indice::inserirVazio(string Elemento){
    pair<string, ListDocumentos> Par;
    Par.first = Elemento;
    ListDocumentos vazia;
    Par.second = vazia;
    this->elementos_.insert(Par);
}
