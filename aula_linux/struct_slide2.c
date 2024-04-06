#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
	char nome[50];
	int ra;
	int idade;
}TipoAluno;

TipoAluno *aloca(int n); // funcao aloca do tipo aluno;
void alterar(TipoAluno *paluno, int n); //funcao que manipula um ponteiro tipo aluno por referencia;
void imprimir(TipoAluno *paluno, int n);

void main(){
	TipoAluno *p;
	
	int n=0, i=0;
	printf("\nInforme o numero de registros");
	scanf("%d", &n);
	
	
	p = aloca(n);
	alterar(p, n);
	for(i=0;i<n;i++){
		printf("\nAluno %s inserido!", (p+i)->nome]);
	}
	imprimir(p, n);
}

TipoAluno *aloca(int n){ 
	TipoAluno *pa; // ponteiro tipo aluno
	
	pa = (TipoAluno *)malloc(sizeof(TipoAluno)*n);
	
	if(pa == NULL) 
		return NULL; //verifica se ponteiro foi alocado corretamente
	return pa;
}

void alterar(TipoAluno *paluno, int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("\nREGISTRO %d", i+1);
		printf("\nInforme nome: ");
		fgets((paluno+i)->nome, 50, stdin);
		//setbuf(stdin, NULL); //limpar buffer teclado.
		(paluno+i)->nome[strcspn((paluno+i)->nome, "\n")] = '\0';
		printf("\nInforme ra: ");
		scanf("%d", &((paluno+i)->ra));
		printf("\nInforme idade: ");
		scanf("%d", &((paluno+i)->idade));
	}
}

void imprimir(TipoAluno *paluno, int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("\n\tALUNO %d", i);
		printf("\nNome: %s", (paluno+i)->nome);
		printf("\nR.A: %d", (paluno+i)->ra);
		printf("\nIdade %d", (paluno+i)->idade);
	}
}
