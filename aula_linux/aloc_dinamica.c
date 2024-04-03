#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	char nome[50];
	int ra;
	int idade;
}TipoAluno;

TipoAluno *aloca(); //prototipo 1
void alterar(TipoAluno *paluno);//prototipo 2
void desaloca(TipoAluno **paluno);//prototipo 3

int main(){
	TipoAluno *p;
	p=aloca();
	alterar(p);
	printf("\nAluno %s inserido!", p->nome);
	desaloca(&p);
	return 0;
}

TipoAluno *aloca(){
	TipoAluno *novo=NULL;
	novo = (TipoAluno *)malloc(sizeof(TipoAluno));
	if(novo)
		return novo;
	else
		return NULL;
}

void alterar(TipoAluno *paluno){
	if(paluno == NULL)
		return;
	printf("\nInforme nome: ");
	fgets(paluno->nome, 50, stdin);
	printf("\nInforme ra: ");
	scanf("%d", &(paluno->ra));
	printf("\ninforme idade: ");
	scanf("%d", &(paluno->idade));
}

void desaloca(TipoAluno **paluno){
	
	if(*paluno){
		free(*paluno);
		*paluno = NULL;
	}
}


