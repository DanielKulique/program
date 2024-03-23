#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x=10, *p=&x;
	float y=12, *p1=&y;
	
	printf("\n%d %f %x %x\n", x, y, p, p1);
	scanf("%d", p);
	scanf("%f", p1);
	printf("\n%d %f %x %x\n", x, y, p, p1);
}
