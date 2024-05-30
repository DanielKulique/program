#include <stdio.h>
#include <stdlib.h>

//fila - fifo - primeiro a entrar é o primeiro a sair 
//A inserção de um novo elemento é feita no final da lista
//A remoção de um elemento é feita no início da lista.

typedef struct no {
    int chave;
    struct no *proximo;
}NO;

typedef struct cabeca{
    NO *inicio;
    NO *final;
}Cabeca;

NO *alocaNO(int chave){
    NO *novo_no = (NO *)malloc(sizeof(NO));
    if(novo_no){
        novo_no->chave = chave;
        novo_no->proximo = NULL;
        return novo_no;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA");
        return NULL;
    }
}

Cabeca *criaPilha(){
    Cabeca *cabeca = (Cabeca *)malloc(sizeof(Cabeca)); //perceba, é uma nova alocacao de memoria apenas para a cabeca;
    if(cabeca){
        cabeca->inicio = NULL;
        cabeca->final = NULL;
        return cabeca;
    }
    else{
        printf("\nMEMORIA NAO ALOCADA PARA A CABECA");
        return NULL;
    }
}

void inserir_final(Cabeca *pilha, int chave){
    NO *novo_no = alocaNO(chave);
    if(novo_no){
        if(pilha->inicio==NULL){
            pilha->inicio=novo_no;
            pilha->final=novo_no;
        }
        else{
            pilha->final->proximo = novo_no;
            pilha->final = novo_no;
        }
    }
}

void remove_inicio(Cabeca *pilha){
    NO *aux = pilha->inicio;
    if(aux == NULL){
        printf("\nFila Vazia!");
        return;
    }
    if(aux->proximo==NULL){ //apenas 1 elemento
        pilha->inicio=NULL;
        pilha->final=NULL;
        free(aux);
    }
    else{
        pilha->inicio = aux->proximo;
        free(aux);
    }
}

void imprime(Cabeca *pilha){
    NO *aux = pilha->inicio;
    if(aux == NULL){
        printf("\nFila Vazia");
        return;
    }
    else{
        while(aux != NULL){
            printf("\n%d", aux->chave);
            aux=aux->proximo;
        }
    }
}

int main(){
    Cabeca *pilha = criaPilha();
    inserir_final(pilha, 1);
    inserir_final(pilha, 2);
    inserir_final(pilha, 3);
    inserir_final(pilha, 4);
    inserir_final(pilha, 5);
    remove_inicio(pilha);
    imprime(pilha);
    return 0;
}

