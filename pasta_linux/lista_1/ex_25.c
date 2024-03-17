//Escreva um programa que leia duas palavras e diga qual deles vem primeiro na ordem
//alfabética. Dica: ‘a’ é menor do que ‘b’.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i=0;
	char l1, l2;
	
	printf("\nDigite a letra 1: ");
	scanf("%c", &l1);
	getchar();
	printf("\nDigite a letra 2: ");
	getchar();
	scanf("%c", &l2);
	
	if((int)l1 == (int)l2)
		printf("Sao os mesmos caracteres");
	else if((int)l1 > (int)l2)
		printf("%c vem antes que %c", l1, l2);
	else
		printf("%c vem antes que %c", l2, l1);
	
	return 0;
}
