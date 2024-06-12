#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
}NO;


void empilhar(NO **p, int chave);//push
void desempilhar(NO **p);//pull
void imprimir(NO *p);

int main(){
	NO *topo = NULL;
	int op=1, chave;
	while(op!=4)
	{
		printf("\n1-Empilhar 2-Desempilhar 3-Imprimir 4-Sair\n");
		scanf("\n%d", &op);
		switch(op)
		{
		case 1:
			{
				printf("\nInforme a chave");
				scanf("\n%d", &chave);
				empilhar(&topo, chave);
				break;
			}
		case 2:
			{
				desempilhar(&topo);
				break;
			}
		case 3:
			{
				imprimir(topo);
				break;
			}
		case 4:
			{
				op = 4;
				break;
			}
		
		}
		imprimir(topo);
	}


	return 0;
}

void empilhar(NO **p, int chave)
{
	NO *novo = NULL;
	novo = (NO *)malloc(sizeof(NO));
	if(novo)
	{
		novo->chave=chave;
		novo->prox=*p;
		*p=novo;
	}
	else{
		printf("\nERRO AO EMPILHAR");
	}
}

void imprimir(NO *p)
{
	if(p==NULL)
		printf("\nPilha Vazia!");
	else
	{
		while(p)
		{
			printf("\n%d", p->chave);
			p=p->prox;
		}
	}
}
void desempilhar(NO **p)
{
	NO *paux=*p;
	if(paux)
	{
		*p = (*p)->prox;
		free(paux);
		paux=NULL;
	}
}


