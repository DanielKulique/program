//concatenar
#include <stdio.h>
#include <stdlib.h>

void *uniao_vet(int *A, int tamA, int *B, int tamB, int **C, int *tamC);
int *alocar_memoria(int tamanho); //retorna um endereço de memoria, por isso tem que ser int
int strTam(int *str);

int main(){
	int *A = NULL, *B=NULL, *C=NULL;
	int tam_a=0, tam_b=0, tam_c;
	int i=0;
	printf("\nTamanho vetor 1:");
	scanf("%d", &tam_a);
	A = alocar_memoria(tam_a);
	for(i=0; i<tam_a;i++){
		printf("\nP[%d]:", i);
		scanf("%d", &(A[i]));
	}
	
	printf("\nTamanho vetor 2:");
	scanf("%d", &tam_b);
	B = alocar_memoria(tam_b);
	for(i=0; i<tam_b;i++){
		scanf("%d", &(B[i]));
		printf("\nP[%d]:", i);
	}
	uniao_vet(A, tam_a, B, tam_b, &C, &tam_c);
	
	for (i=0; i<tam_c;i++){
		printf("%d", C[i]);
	}
	return 0;
}

int strTam(int *str) //retorna um inteiro;
{
	int tamanho=0;
       	while (str[tamanho] != '\0') 
        {
        	tamanho++;
        }
	return tamanho;
}

void *uniao_vet(int *A, int tamA, int *B, int tamB, int **C, int *tamC){
	int i=0, j=0;
	*tamC = tamA + tamB;
	*C = alocar_memoria(*tamC);
	for(i=0;i<tamA;i++){
		(*C)[i] = A[i];
	}
	for(j=0;j<tamB;j++){
		(*C)[i+j] = B[j];
	}
	free(A);
	A = NULL;
	free(B);
	B = NULL;
}

int *alocar_memoria(int tamanho)
{
	int *ptr = NULL;
	ptr = (int *)malloc(sizeof(int)*tamanho);
	if(ptr)
		return ptr;
	else 
		return NULL;
}
