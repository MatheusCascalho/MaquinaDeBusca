//protótipo de testes
#include "teste.h"

bool teste::teste_construtor("Ola mundo"){
    bool resultado;
    if (exp_ == "ola mundo") resultado = true;
    if (vetExp_ == ["ola", "mundo"]) resultado = true;
    else resultado = false;
    return resultado;
}

bool teste::teste_tf("casa", expressao_busca("quem casa quer casa")){
    if (tf("casa") == 2) return true;
    return false;
}