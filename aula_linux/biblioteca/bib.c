#include "bib.h"

int Fatorial(int n);
int Potencia(int base, int exp);
//int SomaFibonacci(int ntermos);
//float MediaAltura(int n);

int Fatorial(int n)
{
	if (n == 0 || n==1)
		return 1;
	else 	
		return n *= Fatorial(n-1);
}

int Potencia(int base, int exp)
{
	int i=0, p=1;
	for(i=0; i<exp;i++)
	{
		p = p * base;
	}
	return p;
}



