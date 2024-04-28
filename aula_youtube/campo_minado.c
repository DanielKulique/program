#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA 10
#define COLUNA 10
#define BOMBAS 20

typedef struct jogo{
    int matrix[LINHA][COLUNA];
    int bombas;
}Campo;

void criar_matriz(Campo *p);
void imprimir_matriz(Campo *p);
//void randomizar_posicoes(int **p);

int main(){
    Campo *ponteiro=NULL;
    ponteiro = (Campo *)malloc(sizeof(Campo));
    if(ponteiro){
        criar_matriz(ponteiro);
        imprimir_matriz(ponteiro);
        free(ponteiro);
    }
    else{
        printf("\nFALHA AO ALOCAR MEMORIA");
    }
    return 0;

}

void criar_matriz(Campo *p){
    int i=0, j=0;

    for(i=0; i<LINHA; i++){
        for(j=0; j<COLUNA; j++){
            p->matrix[i][j] = 0;
        }
    }
}
void imprimir_matriz(Campo *p){
    int i=0, j=0;

    for(i=0; i<LINHA; i++){
        for(j=0; j<COLUNA; j++){
            printf("%d ", p->matrix[i][j]);
        }
        printf("\n");
    }
}

