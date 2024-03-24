#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcula_mediaZero(int num[], float *media, int *num_zero);

int main()
{
	int vetor[100] = {10, 30};
	float media = 0;
	int zeros = 0;
	calcula_mediaZero(vetor, &media, &zeros);
	printf("\n media %.2f", media);
	printf("\n zeros %d", zeros);
}

void calcula_mediaZero(int num[], float *media, int *num_zero){
	int i=0;
	
	for (i=0; i<2; i++)
	{
		*media += num[i];
		if (num[i] == 0)
			*num_zero ++;		
	}
	*media = *media/2;
}
