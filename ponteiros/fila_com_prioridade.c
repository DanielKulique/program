#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

void inserir_com_prioridade(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            // prioridade?
            if(num > 59){
                if((*fila)->valor < 60){ // é a primeira prioridade?
                    novo->proximo = *fila; // insere no inicio da fila
                    *fila = novo;
                }
                else{
                    aux = *fila;
                    while(aux->proximo && aux->proximo->valor > 59)
                        aux = aux->proximo;
                    novo->proximo = aux->proximo; // insere depois da última prioridade;
                    aux->proximo = novo;
                }
            }
            else{
                aux = *fila;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
    else
        printf("\nErro d]ai alocar memoria;\n");
}

No* remover_da_fila(No ** fila){
    No * remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila Vazia\n");
    return remover;
}

void imprimir(No *fila){
    printf("\n\t------------- FILA -------------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t------------- FIM DA FILA -------------\n\t");
}

int main(){
    No *r, *fila = NULL;
    int opcao, valor;

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\t4 - Inserir com prioridade\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_na_fila(&fila, valor);
                break;
            case 2:
                r = remover_da_fila(&fila);
                if(r){
                    printf("Removido: %d\n", r->valor);
                    free(r);
                }
                break;
            case 3:
                imprimir(fila);
                break;
            case 4:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_com_prioridade(&fila, valor);
                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
    
}