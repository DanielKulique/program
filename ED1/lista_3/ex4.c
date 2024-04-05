#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void preencher(struct atleta at);

struct atleta{
	char nome[20];
	int tempos[6];
	int velocidades[6];
	int batimentos[6];
};

int main(){
	int quantidade=0, i=0;
	
	printf("\nInforme quantos atletas estao competindo: ");
	scanf("%d", &quantidade);
	setbuf(stdin, NULL);
	
	struct atleta participantes[quantidade];
	
	for(i=0;i<quantidade;i++){
		printf("\n\tAtleta %d", i);
		printf("\nDigite o nome: ");	
		fgets(participantes[i].nome, 20, stdin);
		setbuf(stdin, NULL);
		int j = 0;
		for(j=0;j<6;j++){
			
			printf("\nDigite o tempo [%d]", j);
			scanf("%d", &participantes[i].tempos[j]);
			printf("\nDigite a velocidade [%d]", j);
			scanf("%d", &participantes[i].velocidades[j]);
			printf("\nDigite os batimentos [%d]", j);
			scanf("%d", &participantes[i].batimentos[j]);
		}
	}
	for(i=0;i<quantidade;i++){
		printf("\n\tAtleta %d", i);
		printf("\n%s", participantes[i].nome);
		int j = 0;
		for(j=0;j<6;j++){
			printf("\n\tcorrida %d", j);
			printf("\nTempo: %d", participantes[i].tempos[j]);
			printf("\nVelocidade: %d", participantes[i].velocidades[j]);
			printf("\nBatimentos [%d]", participantes[i].batimentos[j]);
		}
	}
	return 0;
}


