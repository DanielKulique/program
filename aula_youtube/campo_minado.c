#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA 10
#define COLUNA 10
#define BOMBAS 20

typedef struct jogo{
    int matrix[LINHA][COLUNA];
    int estaAberta[LINHA][COLUNA];
    int bombas;
}Campo;

void criar_matriz(Campo *p);
void randomizar_bombas(Campo *p);
void abrir_posicao(Campo *p, int x, int y);
int bombas_vizinhas(Campo *p, int x, int y);
void imprimir_matriz(Campo *p);
int coordenada_valida(Campo *p, int x, int y);

int main(){
    int x, y, parar=1;

    Campo *ponteiro=NULL;
    ponteiro = (Campo *)malloc(sizeof(Campo)); //aloca memoria para um ponteiro tipo campo
    if(ponteiro){ //se memoria foi alocada
        criar_matriz(ponteiro);
        imprimir_matriz(ponteiro);
        randomizar_bombas(ponteiro);
        do{
            do{
                printf("\nDigite as coordenadas x e y: ");
                scanf("%d %d", &x, &y);
                setbuf(stdin, NULL);
            }while(ponteiro->matrix[x][y] != -1); //repita enquanto a posicao indicada é invalida
            abrir_posicao(ponteiro, x, y);
            imprimir_matriz(ponteiro);
            printf("\nContinua? ");
            scanf("%d", &parar);
        }while(parar);
        free(ponteiro);
    }
    else{
        printf("\nFALHA AO ALOCAR MEMORIA");
    }
    return 0;

}

void criar_matriz(Campo *p){ //preenche matriz
    int i=0, j=0;
    p->bombas = BOMBAS;
    for(i=0; i<LINHA; i++){
        for(j=0; j<COLUNA; j++){
            p->matrix[i][j] = -1;
            p->estaAberta[i][j] = 0;
        }
    }
}
void imprimir_matriz(Campo *p){
    int i=0, j=0;
    printf("\n\n\t     ");
    for(i = 0; i < COLUNA; i++){
        printf("%d    ", i); // INDICE COLUNA
    }
    printf("\n\t   -----------------------------------------\n");

    for(i=0; i<LINHA; i++)
    {
        printf("\t%d  |", i);
        for(j=0; j<COLUNA; j++)
        {
            if(p->estaAberta[i][j] == 1) //esta aberta?
            {
                if(p->matrix[i][j] == -2) //eh bomba
                    printf(" * ");
                else
                    printf(" %d ", p->matrix[i][j]);
            }
            else // esta fechada!
                printf("   ");
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}

void randomizar_bombas(Campo *p){
    int i=0, linha, coluna;
    srand(time(NULL));

    for(i=0; i<BOMBAS; i++){
        linha = rand() % BOMBAS;
        coluna = rand() % BOMBAS;
        if(p->matrix[linha][coluna] != -2)
            p->matrix[linha][coluna] =  -2; //-2 == bomba;
        else
            i--;
    }
}

int coordenada_valida(Campo *p, int x, int y){
      return (x >= 0 && x < LINHA && y >= 0 && y < COLUNA && p->matrix[x][y] < 0);
}

void abrir_posicao(Campo *p, int x, int y){

    if(coordenada_valida(p, x, y))
    {
        p->matrix[x][y] = (bombas_vizinhas(p, x, y));
        p->estaAberta[x][y] = 1;
        printf("vizinhas %d\n", bombas_vizinhas(p, x, y));
        printf("\nABRIU");
        if(bombas_vizinhas(p, x, y) == 0)
        {
            abrir_posicao(p, x+1, y);
            abrir_posicao(p, x-1, y);
            abrir_posicao(p, x, y+1);
            abrir_posicao(p, x, y-1);
        }
    }
        

}

int bombas_vizinhas(Campo *p, int x, int y) {
    int quantidade = 0;

    // Verifica as coordenadas vizinhas e incrementa a quantidade se encontrar uma bomba
    if (coordenada_valida(p, x, y - 1) && p->matrix[x][y - 1] == -2) {
        quantidade++;
        printf("Coordenada (%d, %d), quantidade de bombas vizinhas: %d\n", x, y, quantidade);

    }
    if (coordenada_valida(p, x, y + 1) && p->matrix[x][y + 1] == -2) {
        quantidade++;
        printf("Coordenada (%d, %d), quantidade de bombas vizinhas: %d\n", x, y, quantidade);
    }
    if (coordenada_valida(p, x - 1, y) && p->matrix[x - 1][y] == -2) {
        quantidade++;
        printf("Coordenada (%d, %d), quantidade de bombas vizinhas: %d\n", x, y, quantidade);
    }
    if (coordenada_valida(p, x + 1, y) && p->matrix[x + 1][y] == -2) {
        quantidade++;
        printf("Coordenada (%d, %d), quantidade de bombas vizinhas: %d\n", x, y, quantidade);

    }

    printf("\nQUANTIDADE : %d", quantidade); // Saída para depuração
    return quantidade;
}
