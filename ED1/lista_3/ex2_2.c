#include <stdio.h>
#include <stdlib.h>


struct data{
	int dia;
	int mes;
	int ano;
};

int data(struct data prim, struct data seg);

int main(){
	
	struct data primeira;
	primeira.dia = 3;
	primeira.mes = 5;
	primeira.ano = 2002;
	
	struct data segunda;
	segunda.dia = 1;
	segunda.mes = 4;
	segunda.ano = 2015;
	
	printf("\nTOTAL: %d DIAS", data(primeira, segunda));
	
	return 0;
	
}

int data(struct data prim, struct data seg){
	int dif_ano=0, dif_mes=0, dif_dia=0, dif_tot=0;
	dif_dia = abs(prim.dia - seg.dia);
	dif_mes = abs(prim.mes - seg.mes);
	dif_ano = abs(prim.ano - seg.ano); 
	printf("dif ano: %d, dia %d, mes %d", dif_ano, dif_dia, dif_mes);
	
	dif_tot = ((dif_ano * 365) + (dif_mes*30) + (dif_dia));
	
	return dif_tot;
	
}
