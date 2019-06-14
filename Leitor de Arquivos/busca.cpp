#include <string.h>
#include "busca.h"

using std::string;
using std::map;

Busca::Busca(){

}
Busca::Busca(vector<string> e, Indice i){

    vetExp_ = e;

    // //////////////////TESTE
    // std::cout << "TESTE CONTRUTOR 1: " << std::endl
    // << " primeira palavra: " << vetExp_[0] << std::endl
    // << " segunda palavra: " << vetExp_[1] << std::endl;
    // /////////////////

    for (string palavra: vetExp_){
            // //////////////////TESTE
            // std::cout << "TESTE CONTRUTOR 1.1: " << std::endl
            // << " ENTROU NO FOR - palavra: " << palavra << std::endl;
            // /////////////////

        if(i.aparicoesTotal(palavra) == 0){
            i.inserir(palavra, "expressao");
                // //////////////////TESTE 
                // std::cout << "TESTE CONTRUTOR 1.2: FOI INSERIDO" << std::endl;
                // /////////////////
        } else {
                //////////////////TESTE 
                // std::cout << "TESTE CONTRUTOR 1.3: NAO APARECEU NO INDICE" << std::endl;
                /////////////////
            i.acharDoc(palavra, "expressao");
                //////////////////TESTE 
                // std::cout << "TESTE CONTRUTOR 1.4: CRIOU UM DOCUMENTO" << std::endl;
                /////////////////
            i.incrementar(palavra, "expressao");
                //////////////////TESTE 
                // std::cout << "TESTE CONTRUTOR 1.5: FOI INCREMENTADO" << std::endl;
                /////////////////
        }      
    }
    // //////////////////TESTE
    // std::cout << "TESTE CONTRUTOR 2: " << std::endl
    // << " CONSTRUIDO COM SUCESSO! " << std::endl;
    

    // for (string s : vetExp_){
    //     std::cout << "Teste: " <<  s << " " << i.aparicoesDoc(s, "expressao") << std::endl;
    // }
    /////////////////
}

string Busca::expBusca(){
    string expressao;
    for (string e : vetExp_){
        expressao = expressao + e;
        expressao = expressao + " ";
    }
    return expressao;
}

std::vector<string> Busca::palavrasExpBusca(){
        //////////////////TESTE OPERATOR
        // std::cout << "TESTE palavrasExpBusca 1: ENTROU!" << std::endl;
        /////////////////
    return vetExp_;
}

double Busca::tf(string p){
    int tf = 0;
    transformaString(p);
    for (int i = 0; i < vetExp_.size(); i++){
        if (vetExp_[i] == p) tf++;
    }
    return tf;
}

double Busca::tfmax(Indice i){
    double tfmax = 0;
    std::map<string, ListDocumentos> ind = i.getIndice();
    std::map<string, ListDocumentos>::iterator it;
    for(it = ind.begin(); it != ind.end(); it++){
        map<string, int>::iterator itInterno;
        map<string, int> documentos = it->second.getDocs();
        for (itInterno = documentos.begin(); itInterno != documentos.end(); itInterno++){
            if (itInterno->second > tfmax) tfmax = (itInterno->second);
        }
    }

    return tfmax;
}

double Busca::idf(string p, Indice i){
    transformaString(p);
    double qtdDocs = i.getTodosDocumentos().size();
            // ////////////////////
            // std::cout << "TESTE IDF 1 - QTD DE DOCUMENTOS: "
            // << qtdDocs << std::endl;
            // ///////////////////
        double ondePOcorre;
    if(i.getIndice().find(p) != i.getIndice().end()){
        ondePOcorre = i.getIndice().find(p)->second.retornaLista().size();
    } else {
        //////////////
        // std::cout << "TESTE IDF 1.2 - NAO ACHOU P NO INDICE";
        ondePOcorre = 1;
    }
            // ////////////////////
            // std::cout << "TESTE IDF 2 - QTD DE DOCUMENTOS ONDE A PALAVRA OCORRE: "
            // << ondePOcorre << std::endl;
            ///////////////////

    double idf = log2(qtdDocs/ondePOcorre);
            // ////////////////////
            // std::cout << "TESTE IDF 3 - idf: "
            // << idf << std::endl;
            ///////////////////

    return idf;
}

std::map<string, double> Busca::coordenadaDocsNaPalavra(Indice i, string p)
{
    transformaString(p); //normaliza a palavra
    double freqMax = this->tfmax(i); //encontra a frequencia máxima que uma palavra qualquer pode admitir
    double importanciaDaPalavra = this->idf(p, i); //importancia da palavra p para qualquer documento
    
    std::map<string, double> coordenadasDocs;

    std::map<string, int>::iterator it;
    std::map<string, int> docsNaPalavra = i.getIndice().find(p)->second.getDocs();
    for(it = docsNaPalavra.begin(); it != docsNaPalavra.end(); it++){
        string nomeDoArquivo = it->first;
        double tf = (it->second + 0.0)/freqMax;
        double w = tf * importanciaDaPalavra;
        coordenadasDocs[nomeDoArquivo] = w;
    }
    return coordenadasDocs; 
    
   
}


double Busca::similaridade(Indice i, string doc){
    double num = 0; 
    double coordenadaDocumento = 0, coordenadaExpressao = 0;
    double den_fr1 = 0, den_fr2 = 0;
    
    ////////////////////
    std::cout << "TESTE SIM 1: EM SIMILARIDADE" << std::endl;
    ///////////////////

    for(string palavra : vetExp_){
            ////////////////////
         //   std::cout << "TESTE SIM 2:ENTROU NO FOR" << std::endl;
            ///////////////////        
        coordenadaDocumento = (this->coordenadaDocsNaPalavra(i, palavra).find(doc)->second + 0.0);
            ////////////////////
         //   std::cout << "TESTE SIM 3:CALCULOU COORDENADA DOCUMENTO" << std::endl;
            ///////////////////         
        coordenadaExpressao = (this->coordenadaDocsNaPalavra(i, palavra).find("expressao")->second + 0.0);
            ////////////////////
          //  std::cout << "TESTE SIM 4:CALCULOU COORDENADA EXPRESSAO" << std::endl;
            ///////////////////        
        double prod = coordenadaDocumento * coordenadaExpressao; 
            ////////////////////
         //   std::cout << "TESTE SIM 5:CALCULOU O PRIMEIRO PRODUTO - prod: " 
         //   << prod << std::endl;
            ///////////////////
        num = num + prod;
            ////////////////////
         //   std::cout << "TESTE SIM 6: INCREMENTOU O NUMERADOR - num: " 
         //   << num << std::endl;
            /////////////////// 
        den_fr1 = den_fr1 + coordenadaDocumento;
            ////////////////////
         //   std::cout << "TESTE SIM 7: INCREMENTOU O PRODUTO DA PRIMEIRA FRACAO - DEN_FR1: " 
           // << den_fr1 << std::endl;
            /////////////////// 
        den_fr2 = den_fr2 + coordenadaExpressao;
            ////////////////////
         //   std::cout << "TESTE SIM 8: INCREMENTOU O PRODUTO DA PRIMEIRA FRACAO - DEN_FR2: " 
          //  << den_fr2 << std::endl;
            ///////////////////
    }

    double den = sqrt(den_fr1 * den_fr1) * sqrt(den_fr2 * den_fr2);
    ////////////////////////
    std::cout << "dados: " << std::endl 
    << "numerador: " << num
    << "coordenada documento: " << coordenadaDocumento
    << "coordenada expressao: " << coordenadaExpressao << std::endl;

    if (den == 0){
        return 1;
    }
    ///////
    std::cout<< "denominador: " << den << std::endl;
    //////////////////////
    
    return num/den;
}

map<double, string> Busca::rankingCosseno(Indice i){
    map<double, string> ranking;
    list<string> docs = i.getTodosDocumentos();
    for (string arquivo : docs){
        double pos = this->similaridade(i, arquivo);
        ranking.insert(std::pair<double, string>(pos,arquivo));
    }

    return ranking;
}

void Busca::operator=(Busca b){
    //////////////////TESTE OPERATOR
   // std::cout << "TESTE OPERATOR 1: ENTROU" << std::endl;
    /////////////////
    for (string palavra : b.vetExp_){
        //////////////////TESTE OPERATOR
      //  std::cout << "TESTE OPERATOR 2: ENTROU NO FOR - palavra: " << palavra << std::endl;
        /////////////////
        vetExp_.push_back(palavra);
    }
        //////////////////TESTE OPERATOR
       // std::cout << "TESTE OPERATOR 3: vetExp_ ATRIBUIDO COM SUCESSO!" << std::endl;
        
        /////////////////
    
    //ordemDocumentos_ = b.ordemDocumentos_;
}

void lerUmaFrase(vector<string> &busca){
    int fim = 0;
    string palavra;
    while (!fim){
        std::cin >> palavra;
            if (palavra != "."){
                transformaString(palavra);
                busca.push_back(palavra);
            } else {
                fim = 1;
            }
    }
    std::cout << "A sua busca digitada foi: ";
}
