#include <stdio.h>

void calcMedia(int *array, int n, float *resultado);

int main()
{
	int tam=0, i=0, num=0;
	float resultado=0;
	printf("\nDigite o tamanho do vetor: ");
	scanf("%d", &tam);
	int vetor[tam];
	
	for(i=0;i<tam;i++)
	{
		printf("NUM [%d]", i);
		scanf("%d", &num);
		vetor[i] = num;
	}
	
	calcMedia(vetor, tam, &resultado);
	
	printf("\nMedia = %.4f", resultado);
	return 0;
	
}


void calcMedia(int *array, int n, float *resultado)
{
	int i=0;
	float soma=0; 
	
	for(i=0;i<n;i++)
	{
		soma += *(array+i);
	}
	*resultado = soma/n;
}

