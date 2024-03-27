#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *aloca(int n);
void inicializa(int *v, int n, int valor);
void imprime(int *v, int n);

int main()
{
	int n, *pv;
	printf("\nInforme o numero de elementos: ");
	scanf("%d", &n);
	pv = aloca(n);
	if(pv)
	{
		inicializa(pv, n, 8);
		imprime(pv, n);	
	}
	else
		printf("\nMemoria nao alocada!");
}	

int *aloca(int n)
{
	int *vetor=NULL;
	vetor = (int *)malloc(sizeof(int)*n);
	if(vetor)
		return vetor;
	else
		return NULL;
}	

void inicializa(int *v, int n, int valor)
{
	int i;
	if(v)
	{
		for(i=0;i<n;i++)
			*(v+i) = valor;
	}
}

void imprime(int *v, int n)
{
	int i;
	if(v)
	{
		for(i=0;i<n;i++)
			printf("\n%p %d", (v+i), *(v+i));
	}
}

