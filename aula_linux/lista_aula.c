#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *proximo;
}NO;

void inserir(NO **fila, int valor);
void imprimir(NO *fila);
NO *alocaNO(int k);
void remover(NO **fila);
void removerTodos(NO **fila);
void inserefim(NO **lista, int k);
void removerfim(NO **lista);

int main(){
	NO *prim=NULL, *prim2=NULL;
	imprimir(prim);
	inserir(&prim, 12);
	inserir(&prim, 26);
	inserir(&prim, 44);
	inserir(&prim, 42);
	inserir(&prim, 23);
	imprimir(prim);
	remover(&prim);
	printf("\n----------------\n");
	imprimir(prim);
	printf("\n----------------\n");
	inserefim(&prim2, 12);
	inserefim(&prim2, 13);
	inserefim(&prim2, 14);
	inserefim(&prim2, 15);
	imprimir(prim2);
	printf("\n----------------\n");
	removerfim(&prim2);
	imprimir(prim2);
	return 0;
};



void removerfim(NO **lista){
	NO *aux=*lista, *ant=*lista;
	if(*lista==NULL)
		printf("\nLista vazia!");
	else{
		if((*lista)->proximo==NULL)
		{
			free(*lista);
			*lista=NULL;
		}
		else
		{
			while(aux->proximo)
			{
				ant=aux;
				aux=aux->proximo;
			}
			free(aux);
			ant->proximo=NULL;
		}
	}


}


NO *alocaNO(int k){
	NO *novo=NULL;
	novo = (NO *)malloc(sizeof(NO));
	if(novo) { //novo !=nulo
		novo->valor = k;
		novo->proximo = NULL;
	}
	return novo;
}

void remover(NO **fila){
	NO *aux;
	aux = *fila;
	
	if(*fila){
		*fila = (*fila)->proximo; //endereco tal, no campo proximo
		free(aux);
		aux = NULL;
	}
	else("\nLista vazia!");

};


void removerTodos(NO **fila){
	NO *aux;
	aux = *fila;
	
	while(*fila){		
		if(*fila){
			*fila = (*fila)->proximo; //endereco tal, no campo proximo
			free(aux);
			aux = NULL;
		}
		else("\nLista vazia!");
	}
}

void inserir(NO **lista, int k){
	NO *novo = NULL;
	novo = alocaNO(k);
	if(novo)
	{
		novo->proximo = *lista;
		*lista = novo;
	}
}

void imprimir(NO *lista){
	if(lista==NULL)
		printf("lista vazia");
	else{
		while(lista){
			printf("\n%d", lista->valor);
			lista=lista->proximo;
		}
	}
}

void inserefim(NO **lista, int k){
	NO *aux=*lista, *novo=NULL;
	
	if(*lista==NULL){
		novo = alocaNO(k);
		if(novo)
			*lista=novo;
	
	}
	else{
		while(aux->proximo){
			aux=aux->proximo;
		}
		novo = alocaNO(k);
		if(novo)
			aux->proximo = novo;
	}

}
