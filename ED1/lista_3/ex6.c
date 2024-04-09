#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char nome[16];
	int preco;
	int quantidade;
}Produto;

void preencher(Produto *vetor);
void comprar(Produto *vetor, int codigo, int quantidade);
void imprimir(Produto *vetor);

int main(){
	Produto *Vet; //criar um vetor de produto;
	
	Vet = (Produto *)malloc(sizeof(Produto)*5);//alocando memoria para 5 produtos; 
	
	if(Vet)
		printf("\nMemoria alocada com sucesso");
	else{
		printf("\nMemoria nao alocada");
		return -1;
	}
	
	preencher(Vet);
	imprimir(Vet);
	
	int cod=0;
	int quant=0;
	printf("\n\tCOMPRAR")
	printf("\nCodigo do produto: ");
	scanf("%d", &cod);
	printf("\nQuantidade desejada: ");
	scanf("%d", &quant);
	comprar(Vet, cod, quant);
	
	imprimir(Vet);
	
	free(Vet);
	Vet = NULL;
}

void preencher(Produto *vetor){
	int i;
	
	for(i=0;i<5;i++){
		printf("\n\tProduto %d", i+1);
		printf("\nNome: ");
		fgets((vetor+i)->nome, 16, stdin);
		(vetor+i)->nome[strcspn((vetor+i)->nome, "\n")] = '\0'; // tira quebra de linha indesejada;
		setbuf(stdin, NULL); //tira buffer do teclado;
		printf("Codigo: ");
		scanf("%d", &((vetor+i)->codigo));
		setbuf(stdin, NULL);
		printf("Preco: ");
		scanf("%d", &((vetor+i)->preco));
		setbuf(stdin, NULL);
		printf("Quantidade: ");
		scanf("%d", &((vetor+i)->quantidade));
		setbuf(stdin, NULL);
		
	}
}

void imprimir(Produto *vetor){
	int i;
	
	for(i=0;i<5;i++){
		printf("\n\tProduto %d", i+1);
		printf("\nNome: ");
		printf("%s", (vetor+i)->nome);
		printf("\nCodigo: ");
		printf("%d", ((vetor+i)->codigo));
		printf("\nPreco: ");
		printf("%d", ((vetor+i)->preco));
		printf("\nQuantidade: ");
		printf("%d", ((vetor+i)->quantidade));

		
	}
}

void comprar(Produto *vetor, int codigo, int quantidade){
	int i;
	for(i=0;i<5;i++){
		if((vetor+i)->codigo == codigo && (vetor+i)->quantidade >= quantidade){
			printf("\nCompra aprovada!");
			printf("\nProduto: %s", (vetor+i)->nome);
			(vetor+i)->quantidade -= quantidade;
		}
		else
			printf("\nA compra nao eh possivel!");
	}
}
