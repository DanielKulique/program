#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
	char nome[50];
	int ra;
	int idade;
}TipoAluno;

TipoAluno *aloca(); // funcao aloca do tipo aluno;
void alterar(TipoAluno *paluno); //funcao que manipula um ponteiro tipo aluno por referencia;
void imprimir(TipoAluno *paluno);

void main(){
	TipoAluno *p;
	p = aloca();
	alterar(p);
	printf("\nAluno %s inserido!", p->nome);
	imprimir(p);
}

TipoAluno *aloca(){ 
	TipoAluno *pa; // ponteiro tipo aluno
	pa = (TipoAluno *)malloc(sizeof(TipoAluno));
	
	if(pa == NULL) 
		return NULL; //verifica se ponteiro foi alocado corretamente
	return pa;
}

void alterar(TipoAluno *paluno){
	printf("\nInforme nome:");
	fgets(paluno->nome, 50, stdin);
	//setbuf(stdin, NULL); //limpar buffer teclado.
	paluno->nome[strcspn(paluno->nome, "\n")] = '\0';
	printf("\nInforme ra: ");
	scanf("%d", &(paluno->ra));
	printf("\nInforme idade: ");
	scanf("%d", &(paluno->idade));
}

void imprimir(TipoAluno *paluno){
	printf("\n\tALUNO");
	printf("\nNome: %s", paluno->nome);
	printf("\nR.A: %d", paluno->ra);
	printf("\nIdade %d", paluno->idade);
}
