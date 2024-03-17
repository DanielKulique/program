//GRUPO 2: 
//Daniel Kulique
//Gabriel D Laurindo
//Gabriel Caldeira

#include <stdio.h>
#include <stdlib.h>


float potencia(float a, float b)
{
	int i=0;
	float p=1;
	for(i=0; i<b;i++)
	{
		p = p * a;
	}
	return p;
}

float neperiano(int n)
{
	int i=0; 
	float e=0;
	
	if (n<10)
		return -1;
	for (i=0; i<=n; i++)
	{
		e = e + (1/(float)fatorial(i));
	}
	return e;
}

/*int main()
{
	float pot, nep;
	nep = neperiano(10);
	pot = potencia(2, 0);
	printf("\n potencia%.2f", pot);
	printf("\n neperiano%.4f", nep);
	return 0;
}*/
