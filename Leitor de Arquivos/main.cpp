#include "busca.h"
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::map;
using std::vector;

void imprimirList(const list<string> lista){
    for (string E : lista){
        cout << E << endl;
    }
}

void imprimirVector(const vector<string> lista){
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
    int finalizar = 0;
    while (!finalizar){
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
        
        int numResposta = 0, numResposta2 = 0;
        string pergunta1, pergunta2;
        if(perguntaSouN()){
            while (!numResposta){    
                cout << "Menu de alteracao do Sumario:" << endl
                    << "Voce deseja:" << endl 
                    << "Alterar apenas o nome do arquivo Sumario(1)" << endl
                    << "Alterar apenas a localizacao do arquivo Sumario(2)" << endl
                    << "Alterar a localizacao e o nome do arquivo Sumario(3)" << endl
                    << "Cancelar esta operacao(4)" << endl;
                
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

                    case 4:
                        cout << "Voce selecionou cancelar a alteracao do arquivo Sumario." << endl;
                    break;

                    default:
                        cerr << "Operacao selecionada e invalida!" << endl;
                        numResposta = 1;
                    break;
                }
                cout << "Deseja retornar ao Menu de alteracao do Sumario?" << endl;
                if(perguntaSouN()){
                    numResposta = 0;
                }
                system("cls");
            }
            numResposta = 0;
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
            cout << "Menu Principal:" << endl
                 << "Qual operacao voce deseja realizar?" << endl
                 << "Manipulacao do Indice Invertido criado a partir dos arquivos listados no Sumario(1)" << endl
                 << "Acessar funcao de busca(2)" << endl
                 << "Reiniciar o programa(3)" << endl
                 << "Fechar Programa.(4)" << endl;
            cin >> numResposta;

            string frase;
            //Busca minhaBusca;
            map<double, string> resposta;
            vector<string> busca;
            switch(numResposta){
                case 1:
                    cout << "Voce selecionou manipulacao do Indice Invertido." << endl;
                    numResposta2 = 0;
                    system("pause");
                    system("cls");
                    while (!numResposta2){
                        cout << "Manipulacao do Indice Invertido do Sumario " << Sumario.lerNomeCompleto() << "." << endl
                            << "Imprimir elementos do Indice termo a termo(1)" << endl
                            << "Contar o numero de aparicoes de uma palavra em um documento(2)" << endl
                            << "Contar o numero de aparicoes de uma palavra em todo o Indice(3)" << endl
                            << "Voltar ao Menu de Operacoes(4)" << endl;
                        cin >> numResposta2;
                        switch(numResposta2){
                            case 1:
                                cout << "Voce selecionou impressao completa do Indice." << endl;
                                indiceInvertido.imprimirIndiceCompleto();
                                system("pause");
                            break;

                            case 2:
                                cout << "Voce selecionou contar aparicoes de uma Palavra em um Documento." << endl
                                     << "Digite a Palavra que voce quer encontrar no Indice: ";
                                cin >> pergunta1;
                                cout << "Palavra digitada: " << pergunta1 << endl
                                     << "Digite em qual documento voce quer saber o numero de aparicoes de " << pergunta1 << ": ";
                                cin >> pergunta2;
                                cout << "Documento digitado: " << pergunta2 << endl
                                     << "A Palavra " << pergunta1 << " apareceu [" << indiceInvertido.aparicoesDoc(pergunta1, pergunta2)
                                     << "] vezes no Documento " << pergunta2 << "." << endl;   
                            break;

                            case 3:
                                cout << "Voce selecionou contar aparicoes de uma Palavra em todo o Indice." << endl
                                     << "Digite a Palavra que voce quer encontrar no Indice: ";
                                cin >> pergunta1;
                                cout << "Palavra digitada: " << pergunta1 << endl
                                     << "A Palavra " << pergunta1 << " apareceu [" << indiceInvertido.aparicoesTotal(pergunta1)
                                     << "] vezes no Indice Invertido." << endl;   
                            break;

                            case 4:
                                cout << "Voce selecionou voltar ao Menu Principal." << endl;
                            break;

                            default:
                                cerr << "Operacao selecionada e invalida!" << endl;
                                numResposta2 = 1;
                            break;
                        }
                        cout << "Deseja retornar ao Menu de manipulacao do Indice?" << endl;
                        if(perguntaSouN()){
                            numResposta2 = 0;
                            numResposta = 0;
                        }
                    }
                    numResposta2 = 1;
                    numResposta = 0;    
                break;

                case 2:
                {
                    cout << "Voce selecionou a funcao de busca." << endl
                         << "Digite a sua busca(use um espaco seguido de um ponto para indicar que finalizou): ";  
                    lerUmaFrase(busca);
                    cout << "frase: " << endl;
                    imprimirVector(busca);
                    cout << "Iniciando procedimento de Busca" << endl;
                    Busca query(busca, indiceInvertido);
                    // cout << "TESTE DE FOI CONSTRUIDO MESMO: " << query.palavrasExpBusca()[0] << endl;
                    // cout<< "TESTANDO VETOR EXPBUSCA: "<< query.palavrasExpBusca()[0] <<endl;
                    // map<string, double>::iterator it;
                    // map<string, double> coordenadas = query.coordenadaDocsNaPalavra(indiceInvertido, "a");
                    // for (it = coordenadas.begin(); it != coordenadas.end(); it++){
                    //     string arq = it->first;
                    //     cout << "Nome do documento: " << it->first
                    //         << " e o peso e: " << it->second 
                    //         << " tf: "<< indiceInvertido.getIndice().find("a")->second.lerOcorrencias(arq) 
                    //         << " idf: " << query.idf("a", indiceInvertido) << endl
                    //         << " similaridade: " << query.similaridade(indiceInvertido, arq)<< endl;
                    // }
                    
                    
                    resposta = query.rankingCosseno(indiceInvertido);

                    cout << "A pesquisa retornou " << resposta.size() <<" Documentos. Documentos relacionados: " << endl;
                    for (pair<double, string> par : resposta){
                            cout << par.second << endl;
                    }
                    cout << "FIM DA PESQUISA" << endl;
                    system("pause");
                    numResposta2 = 1;
                    numResposta = 0;
                }
                     
                break;

                case 3:
                    cout << "Voce escolheu reiniciar o programa." << endl;
                break;

                case 4:
                    cout << "Voce escolheu fechar o programa." << endl;
                    finalizar = 1;
                break;

                default:
                    cerr << "Operacao selecionada e invalida!" << endl;
                break;
            }
            cout << "Deseja voltar ao Menu Principal?" << endl;
            if(perguntaSouN()){
                numResposta = 0;
                if(numResposta2){
                    numResposta2 = 0;
                }
            } else if(numResposta2){
                cout << "Deseja encerrar o programa?" << endl;
                if(perguntaSouN()){
                    numResposta = 1;
                    finalizar = 1;
                } else {
                    cout << "Reiniciando..." << endl;
                    system("pause");
                    numResposta = 1;
                    numResposta2 = 0;
                }
            }
            system("cls");
        }

    /*cout << "Bem vindo ao leitor de Arquivos" << endl;

    Busca q(expressaoBusca, meuIndice);
    map<double, string> resposta = q.rankingCosseno(meuIndice);
    cout << "A pesquisa retornou" << resposta.size() <<"Documentos. Documentos relacionados: " << endl;
    map<double, string>::iterator it;
    for (it = resposta.begin(); it != resposta.end(); it++){
          cout << it->second << endl;
    }
    cout << "FIM DA PESQUISA" << endl; 
*/
    }
    cout << "Fechando programa..." << endl;
    system("pause");
    return 0;
}
