#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *procurar(int *vetor,int *tam,int *referencia);

 int main()
 {
 	int vet[] = {1,4,7,2,9,3,6,8};
 	int ref = 9;
 	int tam, *resp;
 	tam = sizeof(vet)/sizeof(vet[0]);
 	resp = procurar(vet, &tam, &ref);
 	printf("REPOSTA: %p\n", resp);
 	return 0;
 }
 
 int* procurar(int *vetor,int *tam,int *referencia)
 {
 	if(vetor==NULL)
 		return NULL;
 			
 	int i=0;
 	for (i=0; i<*tam; i++)
 	{
 		if (vetor[i] == *referencia) // (*(vetor+i)==*referencia)
 			return &vetor[i]; //(vetor+i)
 	}
 	return NULL;
 }
