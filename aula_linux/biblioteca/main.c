#include "bib.h"
#include <stdio.h>

int Fatorial(int n);
int Potencia(int base, int exp);

int main()
{
	int fat;
	int pot;
	fat = Fatorial(5);
	pot = Potencia(5, 2);
	printf("\nfatorial %d", fat);
	printf("\npotencia %d", pot);
	printf("\n");
	return 0;
}
