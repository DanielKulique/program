#include <stdlib.h>
#include <stdio.h>

int main()
{
	int x=5;
	int *p;
	p = &x;
	printf("p=%ld\n", p);
	p++;
	printf("p=%ld\n", p);
	p = p + 15;
	printf("p=%ld\n", p);
	p = p - 2;
	printf("p=%ld\n", p);
	return 0;
}
