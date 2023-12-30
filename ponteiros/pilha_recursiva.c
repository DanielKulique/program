#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* empilhar (No *pilha, int num) {
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
    return NULL;
}
