#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
    CELULA
    eBomba 0 ou 1
    estaAberta o ou 1
    vizinhos 0 a 4
*/

typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
}Celula;

//variaveis globais
Celula jogo[10][10];
int l, c, tam = 10;

// procedimento para inicializar a matriz do jogo

void inicializarJogo()
{
    for(l = 0; l < tam; l++)
    {
        for(c = 0; c <tam; c++)
        {
            jogo[l][c].eBomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
        }  
    }
}

//procedimento para sortear n bombas

void sortearBombas(int n)
{
    int i;
    srand(time(NULL));
    for(i=1; i <=n; i++)
    {
        l = rand() % tam;
        c = rand() % tam;
        if(jogo[l][c].eBomba == 0)
            jogo[l][c].eBomba = 1;
        else
            i--;
    }
}

/*
    funcao que diz se um par de coordenadas é valida ou nao
    1 é valida
    0 não é valido
*/
int coordenadaEhvalida(int l, int c)
{
    if(l >= 0 && l < tam && c >=0 && c < tam)
        return 1;
    else
        return 0;
}

/*
    funcao que retorna a quantidade de bombas na vizinhança de l c
    n - quantidade de bombas
*/

int quantbombasVizinhas(int l, int c)
{
    /*
        l-1 e c cima
        l+1 e c baixo
        l e c + 1 direita
        l e c - 1 esquerda
    */
    int quantidade = 0;

    if(coordenadaEhvalida(l - 1, c) && jogo[l-1][c].eBomba)
        quantidade++;
    if(coordenadaEhvalida(l + 1, c) && jogo[l+1][c].eBomba)
        quantidade++;
    if(coordenadaEhvalida(l, c + 1) && jogo[l][c+1].eBomba)
        quantidade++;
    if(coordenadaEhvalida(l, c - 1) && jogo[l][c-1].eBomba)
        quantidade++;
    
    return quantidade;
}


//procedimento para contar as bombas vizinhas
void contarBombas()
{
    for(l = 0; l < tam; l++)
    {
        for(c = 0; c <tam; c++)
        {
            jogo[l][c].vizinhos = quantbombasVizinhas(l, c);
        }  
    }
}

void imprimir()
{
    printf("\n\n\t     ");
    for(l = 0; l < tam; l++) 
        printf("%d   ", l);  // indice colunas
    printf("\n\t   -----------------------------------------\n");

    for(l = 0; l < tam; l++)
    {
        printf("\t%d  |", l); //indices da linha
        for(c = 0; c < tam; c++)
        {
            if(jogo[l][c].estaAberta)
            {
                if(jogo[l][c].eBomba)
                    printf(" * ");
                else
                    printf( " %d ", jogo[l][c].vizinhos);
            }
            else 
                printf("   ");
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}

//procedimento para abrir a coordenada digitada pelo usuario
void abrirCelula(int l, int c){
    if(coordenadaEhvalida(l, c) == 1 && jogo[l][c].estaAberta == 0){
        jogo[l][c].estaAberta = 1;
        if(jogo[l][c].vizinhos == 0){
            /*
                l-1 e c acima
                l+1 e c abaixo
                l e c + 1 direita
                l e c - 1 esquerda 
            */
        abrirCelula(l-1, c);
        abrirCelula(l+1, c);
        abrirCelula(l, c+1);
        abrirCelula(l, c-1);
        }
    }
}

/*
    funcao para verificar a vitoria
    1 - ganhou
    0 - nao ganhou ainda
*/
int ganhou() {
    int quatidade = 0;

    for(l = 0; l < tam; l++)
    {
        for(c = 0; c <tam; c++)
        {
            if(jogo[l][c].estaAberta == 0  && jogo[l][c].eBomba == 0)
                quatidade++;
        }
    }
    return quatidade;
}



//procedimento jogar que faz a leitura das coordenadas

void jogar(){
    int linha, coluna;

    do{
        imprimir();
        do{
            printf("\nDigite as coordenadas de linha e coluna: ");
            scanf("%d%d", &linha, &coluna); 

            if(coordenadaEhvalida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);
                printf("\nCoordenada invalida ou ja aberta!");
        }while(coordenadaEhvalida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);

        abrirCelula(linha, coluna);
    }while(ganhou() != 0 && jogo[linha][coluna].eBomba == 0);

    if(jogo[linha][coluna].eBomba == 1)
        printf("\n\tQue pena! Voce perdeu!\n");
    else
        printf("\n\tPARABENS! VOCE GANHOU!\n");
    imprimir();
}

int main()
{
    int opcao;

    do{
        inicializarJogo();
        sortearBombas(10);
        contarBombas();
        printf("\n\t\t\tCAMPO MINADO\n");
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);

    }while(opcao == 1);

    return 0;
}