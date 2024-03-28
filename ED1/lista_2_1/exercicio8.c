#include <stdio.h>


void MM(int *vetor, int num, int *min, int *max);

int main()
{
	int elementos[100];
	int i=0, num;
	int maior=0, menor=0;
	printf("\nQuantos elementos: ");
	scanf("%d", &num);
	for (i=0; i<num; i++)
	{
		printf("Elemento [%d]", i+1);
		scanf("%d", &elementos[i]);	
	}
	MM(elementos, num, &menor, &maior);
	printf("\nMenor[%d]\nMaior[%d]", menor, maior);		
	return 0;
}

void MM(int *vetor, int num, int *min, int *max)
{
	int i, j=0;

	*min = vetor[0];
	*max = vetor[0];	
	
	for(i=0;i<num;i++)
	{
		if(vetor[i] < *min)
			*min = vetor[i]; // *(vetor+i)
		if(vetor[i] > *max)
			*max = vetor[i];  // *(vetor+i)
					
	}
	j++;
	
}




