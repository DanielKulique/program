#include <stdio.h>
#include <stdlib.h>

struct data{
	int dia;
	int mes;
	int ano;
};

void data(struct data prim, struct data seg);

int main(){
	
	struct data primeira;
	primeira.dia = 3;
	primeira.mes = 5;
	primeira.ano = 2002;
	
	struct data segunda;
	segunda.dia = 1;
	segunda.mes = 4;
	segunda.ano = 2015;
	
	data(primeira, segunda);

	return 0;
	
}

void data(struct data prim, struct data seg){
	printf("\n\tPRIMEIRO");
	printf("\ndia %d \nmes %d \nano %d", prim.dia, prim.mes, prim.ano);
	printf("\n\tSEGUNDO");
	printf("\ndia %d \nmes %d \nano %d", seg.dia, seg.mes, seg.ano);
}
