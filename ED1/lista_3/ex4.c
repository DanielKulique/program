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
		int tempo_medio=0;
		int velocidade_maxima=participantes[i].velocidades[0];
		int amplitude_batimento=0;
		int maior_batimento = participantes[i].batimentos[0], menor_batimento = participantes[i].batimentos[0];
		printf("\n%s", participantes[i].nome);
		int j = 0;
		for(j=0;j<6;j++){
			//tempo medio
			tempo_medio += participantes[i].tempos[j];
			//velocidade maxima
			if(velocidade_maxima<participantes[i].velocidades[j])
				velocidade_maxima = participantes[i].velocidades[j];
			//batimentos
			//maior
			if(maior_batimento < participantes[i].batimentos[j])
				maior_batimento = participantes[i].batimentos[j];
			//menor
			if(menor_batimento > participantes[i].batimentos[j])
				menor_batimento = participantes[i].batimentos[j];
				
		}
		printf("\nNome: %s ", participantes[i].nome);
		tempo_medio = tempo_medio/6;
		printf("\nTempo medio = %d minutos", tempo_medio);
		printf("\nVelocidade Maxima = %d m/s", velocidade_maxima);
		amplitude_batimento = maior_batimento-menor_batimento; 
		printf("\nAmplitude do Batimento Cardiaco = %d", amplitude_batimento);
	}
	return 0;
}


