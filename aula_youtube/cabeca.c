#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No; //estrutura NO

typedef struct{
    No *inicio;
    int tam;
}Lista; //cabeça

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_no_inicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("\nErro ao alocar memoria!\n");
}

void inserir_no_fim(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        //é o primeiro?
        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            aux = lista->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else    
        printf("\nErro ao alocar memoria!\n");
}

//procedimento para inserir no meio
void inserir_no_meio(Lista *lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        //é o primeiro?
        if(lista->inicio==NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("\n\tLista tamanho: %d: ", lista.tam);
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){
    int opcao, valor, anterior;
    Lista lista;

    criar_lista(&lista);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir inicio\n\t2 - inserir fim \n\t3 - inserir Meio \n\t4-Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
                setbuf(stdin, NULL);
                inserir_no_inicio(&lista, valor);
                break;
            case 2:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
                setbuf(stdin, NULL);
                inserir_no_fim(&lista, valor);
                break;
            case 3:
                printf("\nDigite um valor e o valor de referencia: ");
                scanf("%d%d", &valor, &anterior);
                setbuf(stdin, NULL);
                inserir_no_meio(&lista, valor, anterior);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if(opcao != 0)
                    printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
