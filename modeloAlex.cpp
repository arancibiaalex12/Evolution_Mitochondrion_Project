// Protomodelo - Modelo de  Transição ds Individualidade Endossimbiótica
// Autor : Alex Arancibia  com colaboração de Carlos Pietro
// Data de inicio : 12/09/2018
//

#include <iostream>
#include <stdlib.h>  // biblioteca para incluir função rand e malloc
#include <stdio.h>   // permite operações de input and output
#include <fstream>   // tambem permite operações de saida
#include <cstring>   // permite a manipulação de arrays e strings
#include <string>
#include <math.h>  // contem um serie de funções para operações matematicas

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;


double** alocarMatrizDouble(unsigned long long int l)   //  comments :aqui usar ponteiro duplo  , se declara  um vetor e uma matriz  de ponteiro enderañado via  alocação dinamica
{
    double **m = new double*[l];//(double**)malloc(l * sizeof(double*));    // acoloca um vetor de ponteiros  // malloc : Função que aloca um bloco de certo tamanho de bvtes
                                                           // sua estrutura>void malloc ( size t (unsigned integral type ,size (tamanho do bloco de memoria ))

    for (int unsigned long long i = 0; i < l; i++)  //Percorre as linhas do Vetor de Ponteiros
    {
        // aloca uma matriz dinamicamente

        m[i] = new double[l];//(double*) malloc(l * sizeof(double));

        for (unsigned long long int j = 0; j < l; j++)
        {
            // percorre o Vetor de Inteiros atual.
            m[i][j] = 0; // inicializa com 0.
        }
    }

    return m;
}

int** alocarMatrizInt(unsigned long long int l)
{
    int **m = new int*[l];//(int**)malloc(l * sizeof(int*));    // acoloca um vetor de ponteiros

    for (unsigned long long int i = 0; i < l; i++)  //Percorre as linhas do Vetor de Ponteiros
    {
        // aloca uma matriz dinamicamente

        m[i] = new int[l];//(int*) malloc(l * sizeof(int));

        for (unsigned long long int j = 0; j < l; j++)
        {
            // percorre o Vetor de Inteiros atual.
            m [i][j] = 0; // inicializa com 0.
        }
    }

    return m;
}

double** gerarMatrizPayoff(double b, double c, double k,double r, double v)
{
    unsigned long long int l=6; // numero de elementos diferentes

    double **payoff = new double*[l];//(double**)malloc(l * sizeof(double*));    // acolca um vetor de ponteiros

    for (unsigned long long int i = 0; i < l; i++)  //Percorre as linhas do Vetor de Ponteiros
    {
        // aloca uma matriz dinamicamente

        payoff[i] = new double[l];//(double*) malloc(l * sizeof(double));

        for (unsigned long long int j = 0; j < l; j++)
        {
            // percorre o Vetor de Inteiros atual.
            payoff[i][j] = 0; // inicializa com 0.
        }
    }

    payoff [0][0] = r/2;
    payoff [0][1] = r/2;
    payoff [0][2] = 0;
    payoff [0][3] = k*b - c*(1-k)/2;
    payoff [0][4] = k*b - c*(1-k)/2;
    payoff [0][5] = -c*(1-k);

    payoff [1][0] = r/2;
    payoff [1][1] = r/2;
    payoff [1][2] = 0;
    payoff [1][3] = k*b - c*(1-k)/2;
    payoff [1][4] = k*b - c*(1-k)/2;;
    payoff [1][5] = 0 ;

    payoff [2][0] = r;
    payoff [2][1] = r;
    payoff [2][2] = (r-v)/2;
    payoff [2][3] = k*b;
    payoff [2][4] = 0;
    payoff [2][5] = 0;

    payoff [3][0] = (1-k)*b - c*k/2;
    payoff [3][1] = (1-k)*b - c*k/2;
    payoff [3][2] = -c*k;
    payoff [3][3] = r/2;
    payoff [3][4] = r/2;
    payoff [3][5] = 0;

    payoff [4][0] = (1-k)*b - c*k/2;
    payoff [4][1] = (1-k)*b - c*k/2;
    payoff [4][2] = -c*k;
    payoff [4][3] = r/2;
    payoff [4][4] = r/2;
    payoff [4][5] = 0;

    payoff [5][0] = (1-k)*b;
    payoff [5][1] = 0;
    payoff [5][2] = 0;
    payoff [5][3] = r;
    payoff [5][4] = r;
    payoff [5][5] = (r-v)/2;

    return payoff; //Retorna o Ponteiro para a Matriz Alocada
}

pair < int, int > indentificarN(int i, int j, int direcao,int l) // pair<> ?
{
    // Aqui é declarada a função que vai identificar a posição da célula

    switch (direcao)  //  aqui é determinado as condições de contorno periodico do reticulado
    {
    case 0:     // norte

        if  (i == 0)
        {
            i = l-1;
            j = j+0;
        }
        else
        {
            i = i-1;
            j = j+0;
        }
        break;

    case 1:     // leste

        if(j == (l-1))
        {
            i = i+0;
            j = 0;
        }
        else
        {
            i = i+0;
            j = j+1;
        }
        break;

    case 2:     // sul

        if (i == (l-1))
        {
            i = 0;
            j = j+0;
        }
        else
        {
            i = i+1;
            j = j+0;
        }
        break;

    case 3:     // oeste

        if (j == 0)
        {
            j = l-1;
            i = i+0;
        }
        else
        {
            i = i+0;
            j = j-1;
        }
        break;

    case 4:     // nordeste

        if (i == 0)
        {
            i = l-1;
        }
        else
        {
            i = i-1;
        }

        if ( j == (l-1))
        {
            j = 0;
        }
        else
        {
            j = j+1;
        }
        break;

    case 5:     // sudeste

        if (i == (l-1))
        {
            i = 0;
        }
        else
        {
            i = i+1;
        }

        if(j == (l-1))
        {
            j = 0;
        }
        else
        {
            j = j+1;
        }
        break;

    case 6:     // sudoeste

        if(i == (l-1))
        {
            i = 0;
        }
        else
        {
            i = i + 1 ;

        }
        if (j == 0)
        {
            j = l-1;
        }
        else
        {
            j = j-1;
        }
        break;

    case 7:     // noroeste

        if(i == 0)
        {
            i = l-1;
        }
        else
        {
            i = i-1;
        }
        if(j == 0)
        {
            j = l-1;
        }
        else
        {
            j = j-1;
        }
        break;

    default:
        break;
    }

    pair <int,int> vizinho;
    vizinho.first = i;
    vizinho.second = j;

    return vizinho;
}

double scoreCelula (int i, int j, int vizinhos, int l, double ** payoff, int ** matriz)
{
    // calculo do score por celula

    double score = 0; // variavel para armazenar score

    int tipoCelula = matriz [i] [j];
    int tipoVizinho;
    pair<int,int> vizinho;

    for (  int m = 0; m < vizinhos ; m++)   // loop para determinar o score da celula em relacao a vizinhanca,

    {
        vizinho = indentificarN (i, j, m, l);

        tipoVizinho = matriz[vizinho.first][vizinho.second];

        score += payoff[tipoCelula][tipoVizinho];
    }

    return score ;
}

int escolherEstrategia(int i, int j, int vizinhos, int l, double ** score, int ** matriz)
{
    // o tipo vencedor comeca com a primeira celula a ser analisada , se ela for a maior mantem, senao muda

    double scoreVencedor = score[i][j];

    int tipoVencedor = matriz[i][j];
    bool hospedeiroVencedor;

    if (tipoVencedor < 3)
        hospedeiroVencedor = true;
    else
        hospedeiroVencedor = false;

    pair<int,int> vizinho;

    double scoreVizinho = 0;

    int tipoVizinho = matriz [i][j];

    bool hospedeiroVizinho;

    for (  int m = 0; m < vizinhos ; m++)   // loop para determinar o score da celula em relacao a vizinhanca,

    {
        vizinho = indentificarN (i, j, m, l);

        tipoVizinho = matriz[vizinho.first][vizinho.second];
        scoreVizinho = score[vizinho.first][vizinho.second];

        if (tipoVizinho < 3)
            hospedeiroVizinho  = true;
        else
            hospedeiroVizinho = false ;

        if (scoreVizinho > scoreVencedor)
        {
            if ( hospedeiroVencedor == true && hospedeiroVizinho == false)
            {
                tipoVizinho -= 3;
            }
            if (hospedeiroVencedor == false && hospedeiroVizinho == true)
            {
                tipoVizinho += 3 ;
            }

            scoreVencedor = scoreVizinho;
            tipoVencedor = tipoVizinho;
        }
    }

    return tipoVencedor ;
}

char *criarSubDiretorio(char *subDiretorio, int semente)
{
    unsigned long long int n = strlen(subDiretorio);

    char *newSub = new char[n];//(char*) malloc((n+1)*sizeof(char));

    char sementeChar[10];
    sprintf(sementeChar, "%i", semente);

    strcpy(newSub, subDiretorio);

    strcat(newSub,"\\Semente = ");
    strcat(newSub,sementeChar);

    mkdir(newSub);

    return newSub; // aqui a função retorna o subdiretorio dessa simulacao
}

char *criarNomeArquivo(char *subDiretorio, char *nomeArquivo)
{
    unsigned long long int n = strlen(subDiretorio);

    char *newSub = new char[n];//(char*) malloc((n+1)*sizeof(char)); //linha com problema

    strcpy(newSub, subDiretorio);

    strcat(newSub, nomeArquivo);

    return newSub; // aqui a função retorna o subdiretorio dessa simulacao
}


int main(int argc, char *argv[]) // vetor que serve para passar parametros por linha de comando
{
    // PARAMETROS

    int l = 200; // variavel indica tamanho do lado da matriz // 200

    int numeroEstrategias = 6;

    double b = 0.6;
    double c = 0.5;

    double k = 0.6;
    double r = atof(argv[1]);//0.55;
    double v = 0.6;


    int iteracao = 5000;  // numero de iterações em uma unica simulação

    int simulacao = atoi(argv[2]); // 3000  numero de simulações em uma rodada

    int cenarios = 1;

    int vizinhos = 8; // Definindo numero de vizinhos

    double ** payoff = gerarMatrizPayoff(b,c,k,r,v);


    // VETORES E MATRIZES QUE SERAO USADOS PARA EFETUAR AS MEDIDAS

    //#### vamos alocar uma matriz para receber as porcentagens final de estados  em cada simulacao ####

    double porcentagemEstados[numeroEstrategias][simulacao];

    for ( int i = 0 ; i < numeroEstrategias ; i++) // vamos incializar essa matriz com zeros
    {
        for ( int j = 0 ; j< simulacao ; j++)
        {
            porcentagemEstados[i][j] = 0;
        }
    }

    // criaremos tambem um vetor para servir de contador de estados

    int contadorEstados[numeroEstrategias];

    for (int i = 0; i < numeroEstrategias; i++) // vamos inicializar esse vetor com zeros
    {
        contadorEstados[i] = 0;
    }

    double media [numeroEstrategias][cenarios];
    double desvio [numeroEstrategias][cenarios];

    for (int i = 0; i < numeroEstrategias ; i++)
    {
        for (int j = 0; j < cenarios ; j++)
        {

            media[i][j] = 0;
            desvio[i][j] = 0;
        }
    }


    // MATRIZES RESPONSAVEIS PELA DINAMICA DO MODELO

    int ** matrizT0 = alocarMatrizInt(l);    // Declaração da Matriz
    int ** matrizT1 = alocarMatrizInt(l);    // Matriz de Atulaizacao
    double ** score = alocarMatrizDouble(l); // Matriz para armazenar score


        // criando pasta

    char argUm[10];
    strcpy(argUm,argv[1]);

    char argDois[10];
    strcpy(argDois,argv[2]);

    char diretorio[] = "C:\\Users\\alex  arancibia\\Documents\\códigos pro alex\\simulação \\R=";

    strcat(diretorio,argUm);
    strcat(diretorio,"_S=");
    strcat(diretorio,argDois);

    mkdir(diretorio);

    cout << endl << "Diretorio principal criado: " << diretorio << endl << endl;

    // LOOP COM AS SIMULACOES

    for (int m = 0; m < cenarios; m++)      // loop dos cenarios
    {
        double porcentagemArchea = 0.5;     // redefinindo a porcentagem de archeas para o novo cenario

        for(int n = 0; n < simulacao ; n++)  // loop de simulacoes
        {
            cout << "	simulacao = " << n << endl;

            int semente = m*simulacao + n;
            srand(semente);

            cout << "	semente = " << semente << endl << endl;

            char *subDiretorio = criarSubDiretorio(diretorio, semente);

            cout << "	criando subDiretorio:	" << subDiretorio << endl << endl;

            //matrizT0 = alocarMatrizInt(l);  // as matrizes precisam ser zeradas no inicio de cada simulacao
            //matrizT1 = alocarMatrizInt(l);
            //score = alocarMatrizDouble(l);

            double dado; // variaveis para fazer sorteio dos valores de cada celula na matriz
            int dadoE;

            // inicializando a matrizT0 com as estrategias iniciais

            for ( int i = 0 ; i < l ; i++)
            {
                for ( int j = 0 ; j < l ; j++)
                {
                    dado = (double) rand() / RAND_MAX ;

                    // rand gera valor aletorio a divisao por rand max normaliza o valor
                    // o double converte o a divisao entre inteiro em double

                    if (dado < porcentagemArchea)  //determina se eh archea ou bacteria
                    {
                        dadoE = rand()%3;      // determina uma das 3 estrategias
                    }
                    else
                    {
                        dadoE = (rand()%3)+3;  // determina uma das 3 estrategias
                    }

                    matrizT0[i][j] = dadoE;

                    score[i][j] = 0;
                }
            }

            //armazenando a matriz inicial

            char nomeMatrizInicial[] = "\\matrizInicial_.csv";
            char *asteriscoMatrizInicial = criarNomeArquivo(subDiretorio, nomeMatrizInicial);

            //char enderecoMatrizInicial[200];
            //strcpy(enderecoMatrizInicial,asteriscoMatrizInicial);

            cout << "		matrizInicial:	" << asteriscoMatrizInicial << endl;

            ofstream matrizInicial;

            matrizInicial.open(asteriscoMatrizInicial);

            cout << "		matrizInicial criada com sucesso!" << endl << endl;

            for ( int i = 0 ; i < l ; i++)
            {
                for ( int j = 0 ; j < l ; j++)
                {
                    matrizInicial << matrizT0 [i] [j] << ";";
                }
                matrizInicial << endl;
            }

            matrizInicial.close();

            // #### EVOLUÇÃO TEMPORAL DO MÚMERO DE ESTRATÉGIAS

            char nomeEvolucaoTemporal[] = "\\evolucaoTemporal_.csv";
            char *evolucaoTemporal = criarNomeArquivo(subDiretorio, nomeEvolucaoTemporal);

            cout << "		evolucaoTemporal:	" << evolucaoTemporal << endl;

            ofstream graficoTempo;

            graficoTempo.open(evolucaoTemporal);

            cout << "		evolucaoTemporal criada com sucesso!" << endl << endl;


            // #### faremos as iteracoes no loop abaixo ####

            for (int z = 0; z < iteracao; z++) // regra de atualizacao
            {
                //#### em cada iteracao faremos a contagem, por isso precisamos reiniciar os contadores

                for (int i = 0; i < l; i++)   // varre a a matriz
                {
                    for (int j = 0; j < l; j++)
                    {
                        score[i][j] = scoreCelula(i, j, vizinhos, l, payoff, matrizT0);
                    }
                }

                int estrategiaVencedora;  // criamos uma variavel estrategia vencedora para simplificar o loop abaixo

                for (int i = 0; i < l; i++)
                {
                    for (int j = 0; j < l; j++)
                    {
                        estrategiaVencedora = escolherEstrategia(i, j, vizinhos, l, score, matrizT0);

                        matrizT1[i][j] = estrategiaVencedora;

                        // a estrategia vencedora acaba sendo escolhida para cada celula pelo mesmo metodo
                    }
                }

                matrizT0 = matrizT1;

                for (int phi = 0; phi < numeroEstrategias; phi++)
                {
                    contadorEstados[phi] = 0;         // vamos reinicializar esse vetor com zeros

                    for (int i = 0 ; i < l ; i++)   // varre a a matriz
                    {
                        for (int j = 0 ; j < l ; j++)
                        {
                            if (matrizT0[i][j] == phi )
                            {
                                contadorEstados[phi]++; // soma 1 sempre que a estrategia for i
                            }
                        }
                    }
                }

                graficoTempo << z << ";";  // armazeando as informacoes de evolucao temporal

                for (int phi = 0 ; phi < numeroEstrategias ; phi++)
                {
                    graficoTempo << ((double)contadorEstados[phi]/(l*l)) <<";";
                }

                graficoTempo << endl;
            }

            graficoTempo.close();

            // aqui se encerram as iteracoes e as medidas sao feitas sobre a matriz final

            // primeiro vamos armazenar a matriz final

            char nomeMatrizFinal[] = "\\matrizFinal_.csv";
            char *enderecoMatrizFinal = criarNomeArquivo(subDiretorio, nomeMatrizFinal);

            cout << "		matrizFinal:	" << enderecoMatrizFinal << endl;

            ofstream matrizFinal;

            matrizFinal.open(enderecoMatrizFinal); //"MatrizFinal_.csv"

            cout << "		matrizFinal criada com sucesso!" << endl << endl;

            for ( int i = 0 ; i < l ; i++)
            {
                for ( int j = 0 ; j< l ; j++)
                {
                    matrizFinal << matrizT0 [i] [j] << ";";
                }
                matrizFinal << endl;
            }

            matrizFinal.close();

            for (int z = 0; z < numeroEstrategias; z++)
            {
                contadorEstados[z] = 0;         // vamos reinicializar esse vetor com zeros

                for (int i = 0 ; i < l ; i++)   // varre a a matriz
                {
                    for (int j = 0 ; j < l ; j++)
                    {
                        if (matrizT0[i][j] == z )
                        {
                            contadorEstados[z]++; // soma 1 sempre que a estrategia for i
                        }
                    }
                }
            }

            // uma vez que a contagem eh feita precisamos registrar os novos valores no contador

            for (int q = 0; q < numeroEstrategias;  q++) // para cada valor de estado
            {
                porcentagemEstados[q][n] = ((double)contadorEstados[q]/(l*l));

                // a soma total de estrategias eh sempre igual a l*l
            }
        }

        for( int f = 0; f < numeroEstrategias; f++)
        {
            double somaEstrategia = 0;
            double somaQuadrado = 0;

            for (int p = 0 ; p < simulacao; p++)
            {
                somaEstrategia += porcentagemEstados[f][p];

                somaQuadrado += porcentagemEstados[f][p] * porcentagemEstados[f][p];
            }

            double momento2 =  (somaQuadrado / simulacao);
            media[f][m] = (somaEstrategia / simulacao);

            desvio[f][m] = sqrt(momento2 - media[f][m] * media[f][m]);
        }
    }

    cout << endl << endl << "Fim das amostras!!" << endl << endl;

    // #### aqui vamos gerar o arquivo com a matriz em sua configuracao final

    /*
    ofstream resultado;

    char matrizFinal[] = "C:\\Users\\pietr\\OneDrive\\Área de Trabalho\\reunião alex\\subpastas para simulacoes\\L=";

    strcat(matrizFinal,argUm);
    strcat(matrizFinal,"_S=");
    strcat(matrizFinal,argDois);
    strcat(matrizFinal,"\\MatrizFinal_.csv");

    resultado.open(matrizFinal); //"MatrizFinal_.csv"

    for ( int i = 0 ; i < l ; i++)
    {
        for ( int j = 0 ; j< l ; j++)
        {
            resultado << matrizT0 [i] [j] << ";";
        }
        resultado << endl;
    }

    resultado.close();
    */

    // #### aqui vamos armazenar a condicao inicial da matriz em um arquivo

    /* ofstream condicaoInicial;

     condicaoInicial.open("MatrizInicial_.csv");

     for ( int i = 0 ; i < l ; i++)
         {

             for ( int j = 0 ; j< l ; j++)
             {
                 condicaoInicial << matrizT0 [i] [j] << ";";
             }
             condicaoInicial << endl;
         }

    condicaoInicial.clos e();*/

    // #### aqui vamos gerar o arquivo com dados para fazer o grafico

    // os dados para os 8 graficos estarao no mesmo arquivo, em linhas diferentes

    char nomeGraficoI[] = "\\dadosGrafico_1_.csv";
    char *graficoI = criarNomeArquivo(diretorio, nomeGraficoI);

    cout << "	grafico 1:	" << graficoI << endl;

    ofstream grafico;

    grafico.open(graficoI);
    // o arquivo gerado vai ter 6 linhas, cada um com a porcentagem da media das estrategias em todos as sementes e os desvios

    cout << "	grafico 1 criado com sucesso!" << endl << endl;

    for (int j = 0; j < cenarios; j++)
    {
        for (int i = 0 ; i < numeroEstrategias; i++)
        {
            grafico << media[i][j] << ";" << desvio[i][j] << endl;
        }
        grafico << endl;
    }

    grafico.close();

    char nomeGraficoII[] = "\\dadosGrafico_2_.csv";
    char *graficoII = criarNomeArquivo(diretorio, nomeGraficoII);

    cout << "	grafico 2:	" << graficoII << endl;

    ofstream grafico2;

    grafico2.open(graficoII);
    // o arquivo gerado vai ter uma linha para cada semente com a porcentagem de cada estrategia

    cout << "	grafico 2 criado com sucesso!" << endl << endl;

    for (int p = 0 ; p < simulacao ; p++)
    {
        grafico2 << p <<";"<< porcentagemEstados[0][p]<<";"<< porcentagemEstados[1][p]<<";"<< porcentagemEstados[2][p]<< ";"<<  porcentagemEstados[3][p]<<";"<< porcentagemEstados[4][p] << ";"<< porcentagemEstados[5][p]<<";"<< endl;
    }

    grafico2.close();

    return 0;
}
