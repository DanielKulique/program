#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

int main(void){
	ContaBancaria conta1;
	Inicializa(&conta1, 918556, 300);
	printf("\nAntes da movimentacao:\n");
	Imprime(conta1);
	Deposito(&conta1, 50);
	Saque(&conta1, 70);
	printf("\nDepois da movimentacao:\n");
	Imprime(conta1);
}
