#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *proximo;
}NO;

NO *alocaNO(int chave){
    NO *novo_no = (NO *)malloc(sizeof(NO));
    if(novo_no){
        novo_no->chave = chave;
        novo_no->proximo=NULL;
        return novo_no;
    }
    else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA PARA O NO");
        return NULL;
    }
}

/*NO *crialista(){
    NO *cabeca = (NO *)malloc(sizeof(NO));
    if(cabeca){
        cabeca->proximo = NULL;
        return cabeca;
    }
    else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA PARA O CABECA");
        return NULL;
    }
}*/

void insere_inicio(NO *lista, int chave){
    NO *novo_no = alocaNO(chave);
    if(novo_no){
            novo_no->proximo = lista->proximo;
            lista->proximo = novo_no;
    }
    else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA PARA O NO INICIO");
        return;
    }
}

void imprime(NO *lista){
    if(lista->proximo != NULL){
        NO *aux = lista->proximo;
        while(aux != NULL){
            printf("\n%d", aux->chave);
            aux = aux->proximo;
        }
    }
    else{
        printf("\nLISTA VAZIA");
    }
}

void remove_meio(NO *lista, int referencia){
    NO *aux = lista->proximo;
    if(aux == NULL){
        printf("\nLista Vazia");
        return;
    }
    if(aux->chave==referencia){//chave a ser retirada é o primeiro da lista /
        lista->proximo = aux->proximo; //recebe nulo
        free(aux);
        printf("\nNO REFENCIA RETITRADO %d", referencia);
        return;
    }
    NO* anterior = NULL;
    while(aux != NULL && aux->chave != referencia){
        anterior = aux;
        aux = aux->proximo;
    }
    if(aux == NULL){ //nao foi encontrado no referencia
        printf("\nVALOR NAO ENCONTRADO");
        return;
    }
    if(anterior != NULL){
        anterior->proximo = aux->proximo;
        free(aux);
        printf("\nNO REFERENCIA RETIRADO %d", referencia);
    }
}


int main(){
    NO *cabeca = (NO *)malloc(sizeof(NO));
    if(cabeca){
        cabeca->proximo = NULL;
    }
    else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA PARA O CABECA");
    }
    NO *lista = cabeca;
    insere_inicio(lista, 1);
    insere_inicio(lista, 2);
    insere_inicio(lista, 3);
    insere_inicio(lista, 4);
    insere_inicio(lista, 5);
    imprime(lista);
    return 0;
}

