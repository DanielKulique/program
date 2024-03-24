#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int x=10, *p=&x;
	float y=12, *p1=&y;
	
	printf("\n[valor x: %d] \n[Valor y: %f] \n[end x: %x] \n[end: *p %x]\n [end y: %x]\n [end *p1: %x]\n", x, y, p, &p, p1, &p1);	
	
	scanf("%d", p);
	scanf("%f", p1);
		
	printf("\n[valor x: %d] \n[Valor y: %f] \n[end x: %x] \n[end: *p %x]\n [end y: %x]\n [end *p1: %x]\n", x, y, p, &p, p1, &p1);	
}
