#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char titulo[20];
	char autor[20];
	int ano;
}Livro;

void incluir(Livro *acv, int quant, int posicao);
int cadastrados(Livro *acv);
void imprimir_todos(Livro *acv);
void buscar(Livro *acv);


int main(){
	int p=0, quantidade=0, i=0, cad=0;
	Livro *acervo;
	
	acervo = (Livro*)malloc(sizeof(Livro)*20); // criar espaço na memoria para 20 livros;
	
	if(!acervo){
		printf("\nMemoria nao alocada, erro!");
		return 1;
	}
	
	do{
		cad = cadastrados(acervo);
		if(cad >= 19){
			printf("\nLimite maximo de livros cadastrado!");
			break;
		};
		printf("\nHa %d livros cadastrados, pode cadastrar mais %d", cad, 20-cad);
		printf("\nDigite a quantidade de livros de deseja cadastrar: ");
		do{
			scanf("%d", &quantidade);
			setbuf(stdin, NULL);
				if(quantidade > (19 - cad)){
					printf("\nNao ha espaco suficiente tente menos cadastros!");
					printf("\nDisponivel %d espacos!", cad);
				}
		}while(quantidade > (20 - cad));
		incluir(acervo, quantidade, cad);
		cad += quantidade;
		printf("\nDeseja adicionar mais livros? [0-NAO] [1-SIM]");
		scanf("%d", &p);
		setbuf(stdin, NULL);
	
	}while(p);
	
	
	
	free(acervo);
	acervo = NULL;
};

void incluir(Livro *acv, int quant, int posicao){
	int i=posicao, j=0;
	
	for(j=0; j<quant; j++){
		printf("\n\tLivro %d", i+1);
		printf("\nDigite o titulo do livro: ");
		fgets((acv+i)->titulo, 20, stdin);
		(acv+i)->titulo[strcspn((acv+i)->titulo, ("\n"))] = '\0';
		
		printf("Digite o ano de lancamento: ");
		scanf("%d", &((acv+i)->ano));
		setbuf(stdin, NULL);

		printf("Digite o nome do autor: ");
		fgets((acv+i)->autor, 20, stdin);
		(acv+i)->autor[strcspn((acv+i)->autor, "\n")] = '\0';
		i++;
	}
}

int cadastrados(Livro *acv){
	int i=0;
	while(((acv+i)->titulo[0] != '\0') && i < 20){ // esta sem livro alocado?
		i++;
	}
	return i;
};


void imprimir_todos(Livro *acv){
	int cad, i=0;	
	cad = cadastrados(acv);
	
	if(cad==0){
		printf("\nAcervo Vazio!");
	}
	else{
		for(i=0; i<cad;i++){
			printf("\n\tLivro %d", i+1);
			printf("\nTitulo: ");
			printf("%s", (acv+i)->titulo);
			printf("\nAno: ");
			printf("%d", (acv+i)->ano);
			printf("\nAutor:");
			printf("%d", (acv+i)->autor);
		}
	}
}

void buscar(Livro *acv){
	int cad, i=0;
	char tituloBusca[50];
	cad = cadastrados(acv);
	
	printf("\nDigite o título do livro que deseja buscar: ");
    	fgets(tituloBusca, sizeof(tituloBusca), stdin);
    	tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
	
	for(i=0; i<cad;i++){
		if(strcmp((acv+i)->titulo, tituloBusca)) == 0{
			printf("\n\tLivro %d", i+1);
			printf("\nTitulo: ");
			printf("%s", (acv+i)->titulo);
			printf("\nAno: ");
			printf("%d", (acv+i)->ano);
			printf("\nAutor:")
			printf("%d", (acv+i)->autor);
		
		}
	}
}









