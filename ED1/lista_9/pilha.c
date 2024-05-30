#include <stdio.h>
#include <stdlib.h>

//pilha, adiciona no final, retira do final;
//lifo last in first out
//fifo first in first out

typedef struct no{
    int chave;
    struct no *proximo; 
}NO;

typedef struct cabeca{
    NO *inicio;
    NO *final;
}Cabeca;

NO *AlocaNO(int k){
    NO *novo_no = (NO *)malloc(sizeof(NO));
    if(novo_no){
        novo_no->chave = k;
        novo_no->proximo = NULL;
        return novo_no;
    }
    else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA PARA O NO");
        return NULL;
    }
}

Cabeca *criaPilha(){
    Cabeca *cabeca = (Cabeca *)malloc(sizeof(Cabeca));
    if(cabeca){
        cabeca->inicio = NULL;
        cabeca->final= NULL;
        return cabeca;
    }
    else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA PARA A CABECA");
        return NULL;
    }
}

void adiciona_final(Cabeca *pilha, int chave){
    NO *novo_no = AlocaNO(chave);
    if(novo_no){
        if(pilha->inicio == NULL){
            pilha->inicio = novo_no;
            pilha->final = novo_no;
        }
        else{
            pilha->final->proximo = novo_no;
            pilha->final = novo_no;
        }
    }
    else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA PARA O NO - ADICIONA FINAL");
    }
}

void remove_final(Cabeca *pilha){
    if(pilha->inicio==NULL){
        printf("\nFILA VAZIA");
        return;
    }
    if(pilha->inicio == pilha->final){ //verificando se ha apenas 1 elemento na pilha
        free(pilha->inicio);
        pilha->inicio = NULL;
        pilha->final = NULL;
    }
    else{
        NO *aux = pilha->inicio;
        NO *anterior = NULL;
        while(aux->proximo != NULL){
            anterior = aux;
            aux = aux->proximo;
        }
        free(pilha->final);
        pilha->final = anterior;
        if(pilha->final !=NULL)
            pilha->final->proximo = NULL;
    }
}

void imprime(Cabeca *pilha){
    NO *aux = pilha->inicio;
    if(aux == NULL){
        printf("\nFILA VAZIA");
        return;
    }
    else{
        while(aux != NULL){
            printf("\n%d", aux->chave);
            aux = aux->proximo;
        }
    }
}

int main(){
    Cabeca *pilha = criaPilha();
    adiciona_final(pilha, 1);
    adiciona_final(pilha, 2);
    adiciona_final(pilha, 3);
    adiciona_final(pilha, 4);
    adiciona_final(pilha, 5);
    remove_final(pilha);
    remove_final(pilha);
    remove_final(pilha);
    remove_final(pilha);
    remove_final(pilha);
    remove_final(pilha);
    imprime(pilha);
}