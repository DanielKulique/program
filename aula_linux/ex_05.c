#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i = 5, *p;
	p = &i;
	
	printf("\n%d", **&p+4);
	printf("\n%d", &i);
	
}
