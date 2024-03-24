#include <stdio.h>
#include <stdlib.h>

int main()
{	
	char str[]="abc\0", *c=str;
	printf("\n%c %x", *c, c);
	c++;
	printf("\n%c %x", *c, c);
	c++;
	printf("\n%c %x", *c, c); 
	c++;
	printf("\n%c %x", *c, c);//leitura ilegal
	c++;
	printf("\n%c %x", *c, c);//leitura ilegal
}	
