#include <stdio.h>
#include <stdlib.h>


//inserir em uma fila
//FIFO - primeiro a entrar, primeiro a sair;


typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserirNoInicio(No **fila, int num);
void inserirNoFinal(No **fila, int num);
No* remover(No **fila); // inicio;
void removeNoFinal(No **fila);
void imprimir(No *fila);
No* alocaNO(int valor);


No* alocaNO(int valor){
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = NULL;
    }
    return novo;
}

void inserirNoFinal(No **fila, int num){
    No *aux, *novo;
    aux = *fila;
    if(*fila == NULL){
        novo = alocaNO(num);
        if(novo)
            *fila = novo;
    }
    else{
        while(aux->proximo){
            aux = aux->proximo;
        }
        novo = alocaNO(num);
        if(novo){
            aux->proximo=novo;
        }

    }

}

void inserirNoInicio(No **fila, int num)
{
    No *novo; //criando novo no
    novo = alocaNO(num);//novo = malloc(sizeof(No)); //alocando memoria para o no
    if(novo){
        novo->proximo = *fila;
        *fila = novo;
    }
  
}

void removeNoFinal(No **fila){
    No *aux=*fila, *anterior=*fila;
    if(*fila==NULL)
        printf("\nLista Vazia!");
    else{
        if((*fila)->proximo == NULL){ //tem 1 elemento
            free(*fila);
            *fila = NULL;
        }
        else{
            while(aux->proximo){
                anterior = aux;
                aux = aux->proximo;
            }
            printf("\nValor %d removido", aux->valor);
            free(aux);
            anterior->proximo=NULL;
        }
    }

}


No* remover(No **fila){
    No *remover = NULL;
    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
        return remover;
    }
    else{
        printf("\tFila vazia\n");
    }
    return NULL;
}

void imprimir(No *fila){
    printf("\n\t----- FILA ------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }

    printf("\n\t----- FIM FILA ------\n\t");

}

int main(){
    No *r, *fila = NULL;
    int opcao, valor;

    do{
        printf("\t0-sair\n\t1-inserir\n\t2-remover\n\t3-imprimir\n\t4-insere no final\n\t5-Remove no final\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                setbuf(stdin, NULL);
                inserirNoInicio(&fila, valor);
                break;
            case 2:
                r = remover(&fila);
                if(r){
                    printf("\nRemovido: %d\n", (r)->valor);
                    free(r);
                }
                break;
            case 3:
                imprimir(fila);
                break;
            case 4:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                setbuf(stdin, NULL);
                inserirNoFinal(&fila, valor);
                break;
            case 5:
                removeNoFinal(&fila);
                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}