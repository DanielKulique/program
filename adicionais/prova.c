
#include <stdio.h>
#include <stdlib.h>

int *aloca(int tam);
void informa(int *Vetor, int tam);
void desaloca(int **p);
void imprimir(int *Vetor, int tam);

int main(){
	int *vetor1, *vetor2, *vetor3, *vetor4, par1, par2, par3, par4;

	printf("\nInforme o numero de participantes da cidade 1: ");
	scanf("%d", &par1);
	setbuf(stdin, NULL);
	vetor1 = aloca(par1);
	printf("\n\tCidade 1");
	informa(vetor1, par1);


	printf("\nInforme o numero de participantes da cidade 2: ");
	scanf("%d", &par2);
	setbuf(stdin, NULL);
	vetor2 = aloca(par2);
	printf("\n\tCidade 2");
	informa(vetor2, par2);


	printf("\nInforme o numero de participantes da cidade 3: ");
	scanf("%d", &par3);
	setbuf(stdin, NULL);
	vetor3 = aloca(par3);
	printf("\n\tCidade 3");
	informa(vetor3, par3);

	printf("\nInforme o numero de participantes da cidade 4: ");
	scanf("%d", &par4);
	setbuf(stdin, NULL);
	vetor4 = aloca(par4);
	printf("\n\tCidade 4");
	informa(vetor4, par4);


	printf("\n\tAVALIACOES DO DIA!");
	printf("\n\tCidade 1");
	imprimir(vetor1, par1);
	printf("\n\tCidade 2");
	imprimir(vetor2, par2);
	printf("\n\tCidade 3");
	imprimir(vetor3, par3);
	printf("\n\tCidade 4");
	imprimir(vetor4, par4);

	desaloca(&vetor1);
	desaloca(&vetor2);
	desaloca(&vetor3);
	desaloca(&vetor4);

	return 0;

}

int *aloca(int tam){
	int *v = NULL;
	v = (int *)malloc(sizeof(int)*tam);
	if(!v){
		printf("\nErro de alocacao");
		return 0;
	}
	return v;
}

void desaloca(int **p){
	
	if(*p){
		free(*p);
		*p = NULL;
	}
	else{
		printf("\nERRO AO DESALOCAR");
	}
}



void informa(int *Vetor, int tam){
	int i=0, avaliacao=0;

	for(i=0;i<tam;i++){
		avaliacao=0;
		printf("\nDigite a avaliacao de degustacao %d: ", i+1);
		printf("\n 1 - Excelente 2-Bom 3-Regular 4-Ruim\nDIGITE: ");
		do{
			scanf("%d", &avaliacao);
			//setbuf(stdin, NULL);
			if(avaliacao < 1 || avaliacao > 4){
				printf("Avaliacao nao contabilizada, tente novamente um numero em 1 e 4");
			}
		}
		while(avaliacao < 1 || avaliacao > 4);
		Vetor[i] = avaliacao;
	}

}
void imprimir(int *Vetor, int tam){
	int i=0, ex=0, bom=0, reg=0, ruim=0;

	for(i=0;i<tam;i++){
		//printf("Nota %d", Vetor[i]);
		if(Vetor[i] == 1)
			ex++;
		if(Vetor[i] == 2)
			bom++;
		if(Vetor[i] == 3)
			reg++;
		if(Vetor[i] == 4)
			ruim++;
	}
	printf("\nExelente = %d", ex);
	printf("\nBom = %d", bom);
	printf("\nreg = %d", reg);
	printf("\nruim = %d", ruim);
}

