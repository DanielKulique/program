#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *ant;
	struct no *prox;
}TNo;


TNo *alocaNo(int k);
void insereLista(TNo **p, int k);
void imprimir(TNo *paux);
void removeLista(TNo **p);
void removeTodos(TNo **p);
void insereFim(TNo **p, int k);
void removeFim(TNo **p);
void imprimir_ao_contrario(TNo *paux);

int main(){
	TNo *lista = NULL;
	insereLista(&lista, 42);
	insereLista(&lista, 22);
	insereLista(&lista, 17);
	insereLista(&lista, 16);
	insereLista(&lista, 14);
	imprimir(lista);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++");
	imprimir_ao_contrario(lista);
	//desalocar memoria 
}

TNo *alocaNo(int k)
{
    TNo *novo=NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if(novo) //novo!=NULL
    {
        novo->chave=k;
        novo->ant = NULL;
        novo->prox = NULL;
        
    }
    return novo;
}

void insereLista(TNo **p, int k)
{
   TNo *novo=NULL;
   novo = alocaNo(k);
   if(novo)
   {
       //liga��es dos ponteiros da lista
       novo->prox = *p; //endereco primeiro no da fila da main
       if(*p!=NULL) // o primeiro nao é nulo?
       		(*p)->ant=novo; //anterior olha para novo
       *p = novo; //inicio da lista recebe novo
   }
}

void imprimir(TNo *paux)
{
    if(paux==NULL)
        printf("\nLista vazia!");
    else
    {
        while(paux)
        {
            printf("\n%d", paux->chave);
            paux=paux->prox;
        }
    }
}

void imprimir_ao_contrario(TNo *paux){
	if(paux==NULL){
		printf("\nLista Vazia");
		return;
	}
	while(paux->prox)
		paux=paux->prox;
	while(paux)
	{
		printf("\n%d", paux->chave);
		paux = paux->ant;
	}
	
}




