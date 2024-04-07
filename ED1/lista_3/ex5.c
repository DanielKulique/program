#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[20];
	char ocupacao[10];
	float renda_bruta;
}Pessoa;

void entrada_dados(Pessoa *familia, int membros);
void calculo(Pessoa *familia, int membros);
 
int main(){
	int quant;
	
	printf("\nDigite quantos membros tem na familia: ");
	scanf("%d", &quant);
	setbuf(stdin, NULL);
	
	Pessoa *Familia; //crio um ponteiro do tipo familia
	
	Familia = (Pessoa *)malloc(quant*sizeof(Pessoa)); // aloco dinamicamente esse ponteiro;
	
	if(!Familia){
		printf("\nErro Alocacao");
		return -1;
	}
	
	entrada_dados(Familia, quant); //passo o ponteiro por referencia para a funcao entra_dados;
	calculo(Familia, quant);	
	
	free(Familia);
	Familia = NULL;

	return 0;

}

void entrada_dados(Pessoa *familia, int membros){ //manipula entrada de dados de um ponteiro tipo estrutura Pessoa
	int i=0;
	for(i=0;i<membros;i++){
		printf("\nMembro %d", i+1);
		printf("\nDigite o Nome: ");
		fgets((familia+i)->nome, 20, stdin);
		(familia+i)->nome[strcspn((familia+i)->nome, "\n")] = '\0';
		
		printf("Digite a ocupacao: ");
		fgets((familia+i)->ocupacao, 10, stdin);
		(familia+i)->ocupacao[strcspn((familia+i)->ocupacao, "\n")] = '\0';
		
		printf("Digite a Renda Bruta: ");
		scanf("%f", &(familia+i)->renda_bruta);
		setbuf(stdin, NULL);
	}
}

void calculo(Pessoa *familia, int membros){
	int soma_renda = 0, i=0, per_capita=0;
	
	for (i=0;i<membros; i++){
		soma_renda += (familia+i)->renda_bruta;
	}
	per_capita = soma_renda/membros;
	if(per_capita<1953){
		printf("\nEstudante pode receber o auxilio");
	}
	else
		printf("\nEstudante nao apto ao auxilio");
	
	


}
