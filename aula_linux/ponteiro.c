#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1=15; //variavel
	int *p; //ponteiro
	
	p = &num1;
	printf("\nnum1 = %d", num1); // valor de num1 = 15
	printf("\n&num1= %p", &num1); // endereço de memoria de num1
	printf("\np = %p", p); // endereço de memoria contido em p (endereço de num1) 
	printf("\n*p = %d\n", *p); // valor contido no endereço de memoria de num1, 15.
	return 0;
}
