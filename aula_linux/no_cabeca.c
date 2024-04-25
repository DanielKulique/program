#include <stdio.h>
#include <stdlib.h>


typedef struct no{
	int chave;
	struct no *proximo;
}TNO;

TNO* criaLista();
TNO* alocaNO(int k);
void insereInicio(TNO *p, int k);
void imprime(TNO *paux);
void removeInicio(TNO *p);


int main(){
	TNO *lista = criaLista(); //ponteiro da main vai apontar para um no CABECA;
	//printf("\n%d", lista->chave);
	insereInicio(lista, 11);
	insereInicio(lista, 12);
	insereInicio(lista, 15);
	insereInicio(lista, 17);
	insereInicio(lista, 13);
	imprime(lista->proximo);
	removeInicio(lista);
	printf("\n------------------------------\n");
	imprime(lista->proximo);
	printf("\n------------------------------\n");
	while(lista->proximo){
		removeInicio(lista);
	}
	printf("\n------------------------------\n");
	imprime(lista->proximo);
	return 0;
}


TNO* criaLista(){
	TNO *novo=NULL;
	novo = (TNO *)malloc(sizeof(TNO)); //NO CABECA
	if(novo){
		novo->chave=-1;
		novo->proximo=NULL;
		return novo;
	}
	return NULL;
}

TNO *alocaNO(int k){
	TNO *novo = NULL;
	novo=(TNO *)malloc(sizeof(TNO));
	if(novo){
		novo->chave = k;
		novo->proximo = NULL;
		return novo;
	}
	else
		return NULL;
}

void insereInicio(TNO *p, int k){
	TNO *novo=NULL;
	novo=alocaNO(k);
	if(novo){
		novo->proximo=p->proximo;
		p->proximo = novo;
	}

}

void imprime(TNO *paux){
	if(paux==NULL)
		printf("\nLista Vazia!");
	else{
		while(paux){
			printf("\n%d", paux->chave);
			paux=paux->proximo;
		}
	}
}

void removeInicio(TNO *p){
	TNO *aux= p->proximo;//1 da lista // salva o endereco temporariamento para apagar depois
	if(p->proximo){ // se existir um segundo no
		p->proximo=p->proximo->proximo; //o primeiro no da lista ira apontar para o segundo no
		free(aux); // apagando o primeiro no da lista
	}

}
















