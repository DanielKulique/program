#include <stdio.h>
#include <stdlib.h>


typedef struct no{
	int chave;
	struct no *prox;
}TNo;

TNo *aloca(int k);
void insereLista(TNo **p, int k);
void removeLista(TNo **p);
void imprimeLista(TNo *p);

int main(){
	TNo *lista;
	insereLista(&lista, 22);
	insereLista(&lista, 45);
	insereLista(&lista, 12);
	insereLista(&lista, 53);
	insereLista(&lista, 26);
	imprimeLista(lista);
}


void imprimeLista(TNo *p){
	TNo *paux=NULL;
	if(p==NULL){
		printf("\nLista Vazia");
		return;
	}
	paux=p->prox;
	do{
		printf("\n%d", paux->chave);
		paux=paux->prox;
	}while(paux!= p->prox); //p->prox = primeiro no;

}

void removeLista(TNo **p){

}

void insereLista(TNo **p, int k){
	TNo *novo=NULL;
	novo = aloca(k);
	if(novo){
		*p=novo;
		novo->prox=*p;
	}
	else{
		novo->prox=(*p)->prox;
		(*p)->prox=novo;
		(*p)=novo;	
	}
}


TNo *aloca(int k){
	TNo *novo = NULL;
	novo=(TNo *)malloc(sizeof(TNo));
	if(novo){
		novo->chave = k;
		novo->prox = NULL;
		return novo;
	}
	else
		return NULL;
}
