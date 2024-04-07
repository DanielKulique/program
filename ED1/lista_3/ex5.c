#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	char ocupacao[10];
	float renda_bruta;
}Pessoa;

typedef struct{
	Pessoa *pessoa;
	int quantidade_familia;
}Residencia;

int main(){
	
	Residencia um;
	
	um.pessoa[2];
	
	return 0;
}
