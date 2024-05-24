/*1 – Utilizando uma lista circular, crie as funções de inserção, remoção, busca e exibição
de elementos. */

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int chave;
    struct no *proximo;
}NO;

typedef struct cabeca{
    int quantidade;
    NO *inicio;
    NO *fim;
}Cabeca;

Cabeca* CriaLista(){
    Cabeca *novo = NULL;
    novo = (Cabeca *)malloc(sizeof(Cabeca));
    if(novo){
        novo->inicio=NULL;
        novo->fim = NULL;
        novo->quantidade = 0;
        return novo;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA PARA CABECA");
        return NULL;
    }
}

NO* alocaNO(int k){
    NO *novo_no = NULL;
    novo_no = (NO *)malloc(sizeof(NO));
    if(novo_no){
        novo_no->chave = k;
        novo_no->proximo = NULL;
        return novo_no;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA PARA NOVO NO");
        return NULL;
    }
}

void insereLista(Cabeca *p, int k);
void removeLista(Cabeca *p);
void imprimeLista(Cabeca *p);
void removeTudo(Cabeca *p);
void removeLista_fim(Cabeca *p);
void rotacionar_lista_esquerda(Cabeca *p);
void rotacionar_lista_direita(Cabeca *p);

int main(){
    Cabeca *lista = CriaLista(); // ponteiro lista aponta para no_cabeca;


    insereLista(lista, 1);
    insereLista(lista, 2);
    insereLista(lista, 3);
    insereLista(lista, 4);
    printf("\n----------------------------NORMAL");
    imprimeLista(lista);
    rotacionar_lista_esquerda(lista);
    printf("\n----------------------------ROT1");
    imprimeLista(lista);
    rotacionar_lista_esquerda(lista);
    printf("\n----------------------------ROT2");
    imprimeLista(lista);

    printf("\nfinal = %d", lista->fim->chave);
    
    /*printf("\n----------------------------ROTACIONAR esquerda");
    rotacionar_lista_esquerda(lista);
    imprimeLista(lista);
    printf("\n----------------------------ROTACIONAR esquerda 2");
    rotacionar_lista_esquerda(lista);
    imprimeLista(lista);
    printf("\n----------------------------ROTACIONAR esquerda 3");
    rotacionar_lista_esquerda(lista);
    imprimeLista(lista);*/




    free(lista);
    return 0;
}

void insereLista(Cabeca *p, int k){
    NO *novo = NULL;
    novo = alocaNO(k);
    if(novo){
        if(p->inicio == NULL)
        {
            p->inicio = novo;
            p->fim = novo;
            p->quantidade++;
        }
        else
        {
            novo->proximo = p->inicio;
            p->inicio = novo;
            p->quantidade++;

            //novo->proximo = cabeca->proximo; //novo->proximo = inicio
            //cabeca->proximo = novo; //inicio = novo no;
        }
        p->fim->proximo = p->inicio;
    }
}

void imprimeLista(Cabeca *p){
    NO *aux = p->inicio;
    if(aux == NULL){
        printf("\nLista Vazia!");
    }
    else{
        printf("\nElementos da lista");
        
        do{
            printf(" %d", aux->chave);
            aux = aux->proximo;
        }while(aux != p->inicio);
        printf("\nQuantidade total de elementos = %d", p->quantidade);
    }

}

void removeLista(Cabeca *p){
    NO *aux=NULL;
    aux = p->inicio;
    if(aux==NULL){
        printf("\nLista Vazia!");
        return;
    }
    p->inicio = aux->proximo;
    free(aux);
    p->quantidade--;
    if(p->inicio == NULL)
        p->fim = NULL;
    else if(p->inicio->proximo==NULL)
        p->fim = p->inicio; 
}

void removeTudo(Cabeca *p){
    NO *aux=NULL;
    aux = p->inicio;
    if(aux==NULL){
        printf("\nLista Vazia!");
        return;
    }
    while(p->inicio){
        aux = p->inicio;
        p->inicio = aux->proximo;
        free(aux);
        p->quantidade--;
    }
    if(p->inicio == NULL)
        p->fim = NULL;
    else if(p->inicio->proximo==NULL)
        p->fim = p->inicio; 
}

void insere_Final(Cabeca *p, int valor){
    NO *novo_no = alocaNO(valor);
    if(novo_no){
        if(p->inicio==NULL){//sem no na lista
            p->inicio = novo_no;
        }
        else{
            p->fim->proximo=novo_no;
        }
        p->fim = novo_no;
        p->quantidade++;
        p->fim->proximo = p->inicio;
    }
    else{
        printf("\nERRO AO INSERIR NO FINAL - MEMORIA INSUFICIENTE");
    }
}

void removeLista_fim(Cabeca *p){    
    if(p->inicio == NULL){
        printf("\nLista Vazia!");
    }
    if(p->inicio->proximo == NULL){
        free(p->inicio);
        p->inicio = NULL;
        p->fim = NULL;
        p->quantidade--;
        return;
    }
    
    NO *ant=NULL;
    NO *atual = p->inicio;
    while(atual->proximo){
        ant = atual;
        atual = atual->proximo;
    }
    ant->proximo=p->inicio; // aponta novamente para cabeca inicio
    free(atual);
    p->fim = ant;
    p->quantidade--;
}

void rotacionar_lista_esquerda(Cabeca *p){
    if(p->inicio == NULL){
        printf("\nLista Vazia");
        return;
    }
    if(p->inicio->proximo == p->inicio){//apenas 1 elemento
        printf("\nNada a rotacionar. A lista possui apenas 1 elemento");
        return;
    }
    else{
        p->fim = p->inicio;
        p->inicio = p->inicio->proximo;
    }
}

void rotacionar_lista_direita(Cabeca *p){
    if(p->inicio == NULL){
        printf("\nLista Vazia");
        return;
    }
    if(p->inicio->proximo == p->inicio){//apenas 1 elemento
        printf("\nNada a rotacionar. A lista possui apenas 1 elemento");
        return;
    }
    else{
        NO *anterior = p->inicio, *aux=p->inicio;
        while(anterior->proximo != p->fim){
            anterior = anterior->proximo;
        }

        p->inicio = p->fim;
        p->inicio->proximo = aux;
        p->fim = anterior;  
    }
}