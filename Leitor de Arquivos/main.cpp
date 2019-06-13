#include "busca.h"

using namespace std;

void imprimirList(const list<string> lista){
    for (string E : lista){
        cout << E << endl;
    }
}

bool perguntaSouN(){
    char resposta;
    while(1){
        cout << "Digite 's' para concordar e 'n' para discordar: " << endl;
        cin >> resposta;
        if (resposta == 's'){
            return 1;
        } else if(resposta == 'n'){
            return 0;
        } else {
        cerr << "Caractere invalido! por favor utilize apenas um caractere minusculo 's' ou 'n' para responder!" << endl
             << "Repetindo..." << endl;
        }
    }
}

int main(){
    cout << "Trabalho Pratico de Programacao e Desenvolvimento de Software 2 - 2018/01" << endl
         << "Universidade Federal de Minas Gerais - Campus Pampulha." << endl
         << "Professores: Thiago Ferreira de Noronha, Lucas Victor Silva Pereira.\n" << endl
         << "*--Trabalho Pratico: MAQUINA DE BUSCA--*" << endl
         << "Integrantes do Grupo: " << endl
         << "Bruno Rafael Martins Alves - 2018106753"<< endl 
         << "Joao Vitor David Prates - 2018099382." << endl
         << "Matheus Cascalho dos Santos - 2018014697." << endl;

    system("pause");
    system("cls");

    Diretorio Sumario;
    cout << "Bem vindo(a) a Maquina de Busca!" << endl
         << "Por DEFAULT o Diretorio do Sumario, que sera usado para determinar" << endl
         << "quais arquivos do tipo .txt serao lidos por este programa, esta localizado em: " 
         << Sumario.lerNomeCompleto() << "," << endl
         << "Deseja fazer uma alteracao?" << endl;
    
    int numResposta = 0;
    string pergunta1, pergunta2;
    if(perguntaSouN()){
        while (!numResposta){    
            cout << "Voce selecionou que quer alterar o seu Sumario." << endl
                << "Voce deseja:" << endl 
                << "Alterar apenas o nome do arquivo Sumario(1)" << endl
                << "Alterar apenas a localizacao do arquivo Sumario(2)" << endl
                << "Alterar a localizacao e o nome do arquivo Sumario(3)" << endl
                << "Cancelar esta operacao(4)" << endl;
            
            cin >> numResposta;
            switch(numResposta){
                case 1:
                    cout << "Voce escolheu alterar o nome do arquivo Sumario." << endl
                        << "Nome atual: " << Sumario.lerNome() << endl
                        << "Digite o novo nome: ";
                    cin >> pergunta1;
                        Sumario.setNome(pergunta1);
                        Sumario.concatenarEndereco();
                    cout << "O novo nome do arquivo Sumario agora e: " << Sumario.lerNome() << endl;
                break;

                case 2:
                    cout << "Voce escolheu alterar o endereco do arquivo Sumario" << endl
                        << "Endereco atual: " << Sumario.lerEndereco() << endl
                        << "Digite o novo endereco (por favor, note que em c++ use quatro \\as para representar uma.): ";
                    cin >> pergunta1;
                        Sumario.setEndereco(pergunta1);
                        Sumario.concatenarEndereco();
                    cout << "O novo endereco do arquivo Sumario agora e: " << Sumario.lerEndereco() << endl;
                break;

                case 3:
                    cout << "Voce escolheu alterar o nome e endereco do arquivo Sumario" << endl
                         << "Nome atual: " << Sumario.lerNome() << endl
                         << "Digite o novo nome: ";
                    cin >> pergunta1;
                        Sumario.setNome(pergunta1);
                        Sumario.concatenarEndereco();
                    cout << "O novo nome do arquivo Sumario agora e: " << Sumario.lerNome() << endl
                         << "Endereco atual: " << Sumario.lerEndereco() << endl
                         << "Digite o novo endereco (por favor, note que em c++ use quatro \\as para representar uma.): ";
                    cin >> pergunta1;
                        Sumario.setEndereco(pergunta1);
                        Sumario.concatenarEndereco();
                    cout << "O novo endereco do arquivo Sumario agora e: " << Sumario.lerEndereco() << endl;
                break;

                default:
                    numResposta = 1;
                break;
            }
            cout << "Deseja retornar para alterar o Sumario novamente?" << endl;
            if(perguntaSouN()){
                numResposta = 0;
            }
        }
    }

    cout << "Agora o processo de leitura de arquivos e geracao de um Indice Invertido pode ser realizado." << endl
         << "O Indice sera gerado a partir dos nomes listados" << endl
         << "dentro do arquivo Sumario selecionado:" << endl
         << Sumario.lerNomeCompleto() << "." << endl;

    Indice indiceInvertido(Sumario);
    system("pause");
    system("cls");

    cout << "Com o seu Indice Invertido formado a funcao busca pode ser operada." << endl;
    system("pause");
    while (!numResposta){
        cout << "Qual operacao voce deseja realizar?" << endl
             << "Manipulacao do Indice Invertido criado a partir dos arquivos listados no Sumario(1)" << endl
             << "Acessar funcao de busca(2)" << endl
             << "Fechar Programa.(3)" << endl;
        cin >> numResposta;

        switch(numResposta){
            case 1:
                cout << "Voce selecionou manipulacao do Indice Invertido." << endl;
            break;

            case 2:
                cout << "Voce selecionou a funcao de busca." << endl;
            break;

            case 3:
            break;

            default:
                cerr << "Operacao selecionada e invalida!" << endl;
            break;
        }
        cout << "Deseja voltar ao Menu de Operacoes?" << endl;
        if(perguntaSouN()){
            numResposta = 0;
        }
        system("cls");
    }

    /*cout << "Bem vindo ao leitor de Arquivos" << endl;

    string nomeSaida = "Saida.txt";
    cout << "NomeSaida: " << nomeSaida << endl;

    Diretorio meuDiretorio;
    cout << "Nome: " << meuDiretorio.lerNome() << endl
         << "Endereco: " << meuDiretorio.lerEndereco() << endl
         << "Nome Completo: " << meuDiretorio.lerNomeCompleto() << endl;

    list<string> arquivosPLer;
    acharArquivosPadrao(arquivosPLer);
    imprimirList(arquivosPLer);


    lerArquivos(meuDiretorio, arquivosPLer, nomeSaida);

    cout << "O arquivo Saida.txt deve ter sido preenchido." << endl;

    cout << "Testando a criacao e leitura de um indice: " << endl;

    

    Indice meuIndice(meuDiretorio);
    meuIndice.imprimirIndiceCompleto();

    cout << "Testando leitor de um arquivo:" << endl;

    list<string> palavras;
    meuDiretorio.setNome("bruno.txt");
    meuDiretorio.concatenarEndereco();
    cout << "Lendo todas as palavras de [" << meuDiretorio.lerNomeCompleto() << "]" << endl;;
    lerUmArquivo(meuDiretorio, palavras);
    imprimirList(palavras);

    string pergunta, pergunta2;
    cout << "Digite uma palavra para saber quantas vezes ela apareceu em todos os documentos: " << endl;
    cin >> pergunta;
    cout << "A palavra ["  << pergunta << "] apareceu um total de [" 
         << meuIndice.aparicoesTotal(pergunta) << "] vezes no seu Indice Invertido." << endl;

    cout << "Digite uma palavra e um documento: " << endl;
    cin >> pergunta >> pergunta2;
    cout << "A palavra ["  << pergunta << "] apareceu um total de [" 
         << meuIndice.aparicoesDoc(pergunta, pergunta2) << "] vezes em [" << pergunta2 << "]" << endl;

    string expressaoBusca;
    cout << "Digite uma expressao de busca: " << endl;
    cin >> expressaoBusca;

    Busca q(expressaoBusca, meuIndice);
    map<double, string> resposta = q.rankingCosseno(meuIndice);
    cout << "A pesquisa retornou" << resposta.size() <<"Documentos. Documentos relacionados: " << endl;
    map<double, string>::iterator it;
    for (it = resposta.begin(); it != resposta.end(); it++){
          cout << it->second << endl;
    }
    cout << "FIM DA PESQUISA" << endl;    
*/  
    cout << "Fechando programa..." << endl;
    system("pause");
    return 0;
}
