#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	char nome[50];
	int ra;
	int idade;
}TipoAluno;

TipoAluno *aloca(int tam); //prototipo 1
void alterar(TipoAluno *paluno, int tam);//prototipo 2
void desaloca(TipoAluno **paluno);//prototipo 3

int main(){
	TipoAluno *p;
	int tam, i=0;
	printf("\nInforme a quantidade de alunos: ");
	scanf("%d", &tam);
	p=aloca(tam);
	alterar(p, tam);
	for(i=0; i<tam;i++){
		printf("Aluno %s inserido!\n", (p+i)->nome);
	}
	desaloca(&p);
	return 0;
}

TipoAluno *aloca(int tam){
	TipoAluno *novo=NULL;
	novo = (TipoAluno *)malloc(sizeof(TipoAluno)*tam);
	if(novo)
		return novo;
	else
		return NULL;
}

void alterar(TipoAluno *paluno, int tam){
	if(paluno == NULL)
		return;
	int i = 0;
	for(i=0; i<tam; i++){
		setbuf(stdin, NULL);
		printf("\nInforme nome: ");
		fgets((paluno+i)->nome, 50, stdin);
		setbuf(stdin, NULL);
		printf("\nInforme ra: ");
		scanf("%d", &((paluno+i)->ra));
		setbuf(stdin, NULL);
		printf("\ninforme idade: ");
		scanf("%d", &((paluno+i)->idade));
	}
}

void desaloca(TipoAluno **paluno){
	
	if(*paluno){
		free(*paluno);
		*paluno = NULL;
	}
}


