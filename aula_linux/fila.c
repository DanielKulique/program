#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *proximo;
}NO;

typedef struct cabeca{
	NO *inicio, *fim;
}cabeca;

cabeca *criaFila();
void alocaNO(int k);
void insereFila(cabeca *p, int chave);
void remover(cabeca *p);
void imprime(NO *inicio);
void concatena(cabeca *fim1, cabeca *fim2);



int main(){
	cabeca *fila = criaFila();
	int op=1;
	while(op=!5){
		printf("\n1=inserir 2-remove 3-imprime 4-concatena 5-sai");
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			insereFila(fila, 23);
			insereFila(fila, 53);
			insereFila(fila, 88);
			insereFila(fila, 34);
			insereFila(fila, 22);
			break;
		case 2:
			remover(fila);
			break;
		case 3:
			imprime(fila->inicio);
			break;
		}
	}
	return 0;
}

NO *alocaNO(int k){
	NO *novo = (NO *)malloc(sizeof(NO));
	if(novo){
		return novo;
	}
	else{
		printf("\nERRO AO ALOCAR MEMORIA PARA O NO");
	}
}

cabeca *CriaLista(){
	cabeca *novo = NULL;
	novo = (cabeca *)malloc(sizeof(cabeca));
	if(novo){
		novo->inicio=NULL;
		novo->fim=NULL;
	}
	return novo;
}

void insereFila(cabeca *p, int chave){
	cabeca *novo = (cabeca *)malloc(sizeof(cabeca));
	if(novo){
		novo->chave;
		novo->proximo = NULL;

		if(p->fim != NULL) //se nao tem um proximo na fila, vai ocorrer flha de segmentacao
			p->fim->proximo = novo;
		p->fim = novo;

		if(p->inicio == NULL)//se a fila for vazia
			p->inicio = novo;
	}

}

void imprime(NO *pinicio){
	if(pinicio==NULL)
		printf("\nFILA VAZIA");
	else{
		while(pinicio){
			printf("\n%d", pinicio->chave);
			pinicio = pinicio->proximo;
		}
	}

}
void remover(cabeca *p){
	NO *paux=p->inicio;

	if(paux){
		p->inicio=p->inicio->proximo;//o inicio vai olhar para o segundo/=
		free(paux); //liberando o primeiro no
	}
	else{
		printf("\nFILA VAZIA");
	}
}









