#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	char nome[50];
	int ra;
	int idade;
}TipoAluno;

TipoAluno *aloca(int n);
void alterar(TipoAluno *paluno, int n);

int main(){
	int n, i;
	return 0;
} 
