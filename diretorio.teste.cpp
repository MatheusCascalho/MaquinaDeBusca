#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "diretorio.h"
#include "doctest.h"

using std::string;

class TesteDiretorio {
    public:

    string prefixo(const Diretorio &d){
        return d.prefixo_;
    }
    
    string nomeArquivo(const Diretorio &d){
        return d.nomeArquivo_;
    }

    string nomeCompleto(const Diretorio &d){
        return d.nomeCompleto_;
    }

};

TEST_SUITE("Diretorio"){
  TEST_CASE("Diretorio::Diretorio()"){
    TesteDiretorio teste;
    Diretorio padrao;
    CHECK(teste.prefixo(padrao) == "Diretorio\\\\");
    CHECK(teste.nomeArquivo(padrao) == "Sumario.txt");
    CHECK(teste.nomeCompleto(padrao) == "Diretorio\\\\Sumario.txt");
  }

  TEST_CASE("Diretorio::Diretorio(string, string)"){
    TesteDiretorio teste;
    Diretorio d("banana\\\\", "feijao.txt");
    CHECK(teste.prefixo(d) == "banana\\\\");
    CHECK(teste.nomeArquivo(d) == "feijao.txt");
    CHECK(teste.nomeCompleto(d) == "banana\\\\feijao.txt");
  }

  TEST_CASE("Diretorio::lerNome()"){
    Diretorio d("banana\\\\", "feijao.txt");
    string teste = "feijao.txt";
    CHECK(d.lerNome() == teste);
  }

  TEST_CASE("Diretorio::lerEndereco"){
    Diretorio d("banana\\\\", "feijao.txt");
    string teste = "banana\\\\";
    CHECK(d.lerEndereco() == teste);
  }

  TEST_CASE("Diretorio::lerNomeCompleto"){
    Diretorio d("banana\\\\", "feijao.txt");
    string teste = "banana\\\\feijao.txt";
    CHECK(d.lerNomeCompleto() == teste);
  }


}