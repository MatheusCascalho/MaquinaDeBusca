# MaquinaDeBusca
Trabálho prático de Programação e Desenvolvimento de Software II, Engenharia de Controle e Automação da UFMG.  

Neste trabalho a maquina de busca a ser implementara dará suporte apenas a documentos textuais, que
irão formar a base de dados onde o buscador realizará as consultas determinas pelos usuários.
indice invertido: tabela que relaciona cada palavra do vocabulário com a lista de documentos em que a palavra aparece

Classificação dos resultados de busca: Cada palavra tem um peso no documento. Quanto mais essa palavra aparece no documento, maior o peso dela. O peso é a posição da palavra no vetor.

idf(t) = log(N/nt)

IDF é a importancia da palavra t no documento. O que está expresso na formula matemática de idf é que o peso de uma palavra Px é inversamente proporcional a quantidade de vezes que ela aparece na coleção de documento. Isso porque quanto mais vezes
uma palavras aparece, menos importância ela terá para definir o assunto tratado na consulta.

## Tarefas
* Código que lê os arquivos e cria o índice invertido
 * Ler cada palavra
 * Converter os caracteres maiusculos para minusculos