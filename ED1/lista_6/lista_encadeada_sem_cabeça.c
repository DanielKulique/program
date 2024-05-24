#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *proximo;
}NO;



NO *alocaNO(int chave);
void insere_inicio(NO **p, int chave);
void imprime(NO *p);
void insere_final(NO **p, int chave);
void insere_meio(NO **p, int chave, int referencia); 
void remove_meio(NO **p, int chave, int referencia);

int main (){
    NO *lista = NULL;
    insere_final(&lista, 22);
    insere_final(&lista, 16);
    insere_final(&lista, 27);
    insere_final(&lista, 34);
    insere_final(&lista, 43);
    insere_meio(&lista, 20, 27);
    imprime(lista);

    return 0;
}

NO* alocaNO(int chave){
    NO *novo_novo = (NO *)malloc(sizeof(NO*));
    if(novo_novo){
        novo_novo->chave = chave;
        novo_novo->proximo = NULL;
        return novo_novo;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA PARA O NO");
        return NULL;
    }
}

void insere_inicio(NO **p, int chave){
    NO* novo_no = alocaNO(chave);
    if(novo_no){
        novo_no->proximo = *p;
        *p = novo_no;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA INSERIR INICIO");
    }
}

void imprime(NO *p){
    while(p){
        printf("\n%d", p->chave);
        p = p->proximo;
    }
}

void insere_final(NO **p, int chave){
    NO *novo_no = alocaNO(chave);
    if(novo_no){
        if((*p) == NULL){
            *p = novo_no;
        }
        else{
            NO *aux = *p;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo_no;
        }
    }
    else{
        printf("\nERRO AO ALOCAR NO");
    }
}

void insere_meio(NO **p, int chave, int referencia){
    NO *novo_no = alocaNO(chave);
    if(novo_no){
        if((*p) == NULL){ //se nao tiver no
            *p = novo_no;
        }
        else{
            NO *aux = *p;
            NO *anterior = NULL;
            while(aux->chave != referencia && aux->proximo != NULL){
                anterior = aux;
                aux = aux->proximo;
                printf("\nesta aqui o erro");
            }
            if(aux->proximo == NULL){
                aux->proximo = novo_no;
            }
            else{
                novo_no->proximo = aux;
                anterior->proximo = novo_no;
            }
        }
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA - INSERE MEIO");
    }

}