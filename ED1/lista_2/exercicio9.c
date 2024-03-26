#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y);

int main()
{
	int num1 = 10, num2 = 30;
	printf("\t\nANTES: \nnum1 [%d] \nnum2 [%d]", num1, num2);
	swap(&num1, &num2);
	printf("\t\nDEPOIS: \nnum1 [%d] \nnum2 [%d]", num1, num2);
	
	return 0;
}

void swap(int *x, int *y)
{
	int aux=0;
	aux = *x;
	*x = *y;
	*y = aux;
}
