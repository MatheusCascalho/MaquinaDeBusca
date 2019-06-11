#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <list>
#include <math.h>
#include "Leitor de Arquivos/indice.h"
#include "busca.h"

using std::string;

void normalizaString(string& valor){
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

Busca::Busca(string e){
    exp_ = e;

    int primeiraLetra = 0; //posição da primeira letra de uma palavra
    string palavra;
    for (int i = 0; i < strlen(e.c_str()); i++){
        if ((e[i]==' ')||(e[i]=='.')||(e[i]==',')||(e[i]=='?')){
            palavra = e.substr(primeiraLetra, i - 1);
            //normalizaString(palavra);
            transformaString(palavra); //normaliza a palavra
            vetExp_.push_back(palavra); //armazena a palavra no vetor
            primeiraLetra = i + 1; //primeira letra da próxima palavra
        }
    }

}