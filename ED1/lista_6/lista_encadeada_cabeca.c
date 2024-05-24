#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *proximo;
}NO;


NO *aloca_NO(int valor);
NO *cria_lista(); //retorna um no cabeca
void inserir_inicio(NO *cabeca, int valor);
void remover_inicio(NO *cabeca);
void imprimir_lista(NO *cabeca);

int main(){
    NO *lista = cria_lista(); //ponteiro ira aponta para a cabeca da fila; 

    inserir_inicio(lista, 43);
    inserir_inicio(lista, 53);
    inserir_inicio(lista, 14);
    inserir_inicio(lista, 34);
    inserir_inicio(lista, 26);
    imprimir_lista(lista);
    printf("\n--------------------removendo 1 elemento----------------------\n");
    remover_inicio(lista);
    imprimir_lista(lista);
    return 0;
}

NO *cria_lista(){
    NO *cabeca = NULL;
    cabeca = (NO *)malloc(sizeof(NO));
    if(cabeca){
        cabeca->proximo = NULL;
        return cabeca;
    }
    else{
        printf("\nERRO AO CRIAR CABECA");
        return NULL;
    }
};

NO *aloca_NO(int valor){
    NO *novo_no = (NO *)malloc(sizeof(NO));
    if(novo_no){
        novo_no->chave = valor;
        novo_no->proximo = NULL;
        return novo_no;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA!");
        return NULL;
    }
};


void inserir_inicio(NO *cabeca, int valor){
    NO *novo_no = NULL;
    novo_no = aloca_NO(valor);

    if(novo_no){
        novo_no->proximo = cabeca->proximo; //cabeca->proximo aponta para o primeiro no ou nulo; //novo->proximo vai apontar para segundo no(anteriormente primeiro no)
        cabeca->proximo = novo_no; //agora cabeca vai apontar para o novo no alocado;
    }
    else{
        printf("\nERRO AO INSERIR ELEMENTO");
    }
};

void remover_inicio(NO *cabeca){
    NO *aux = cabeca->proximo;
    if(aux == NULL){
        printf("\nLista Vazia");
    }
    else{
        if(cabeca->proximo){//se tem um segundo elemento // se nao tiver vai ocorrer falha de segmentacao
            cabeca->proximo = aux->proximo; //cabeca ira apontar para o segundo elemento
            free(aux);
        }
        else{
            cabeca->proximo = NULL;
            free(aux);
        }
    }
};

void imprimir_lista(NO *cabeca){
    NO *aux = cabeca->proximo;
    if(aux == NULL){
        printf("\nLista Vazia!");
    }
    else{
        while(aux){
            printf("\n%d", aux->chave);
            aux = aux->proximo;
        }
    }
};


