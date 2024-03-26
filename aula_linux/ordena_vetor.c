#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordena_vetor(int *vetor);

int main()
{
	int i;
	int vetor_num[] = {1,5,7,2,4,6};
	ordena_vetor(vetor_num);
	for (i=0; i<6;i++)
	{
		printf("%d ", vetor_num[i]);
	}	
	return 0;
}

void ordena_vetor(int *vetor)
{
	int i=0, j=0;
	int aux=0, troca=0;
	

	do{	
		troca = 0;
		for(i=0;i<5;i++)
		{
			//printf("%d", vetor[i]);
			if(vetor[i] > vetor[i+1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				troca=1;
			}
		}
	}while(troca);
}
