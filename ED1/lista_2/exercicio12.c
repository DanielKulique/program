#include <stdio.h>
#include <string.h>

int string(char *string);


int main()
{
	char nome[100];
	printf("\nDigite a frase:");
	fgets(nome, 100, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	printf("\nCaracteres: %d", string(nome)); 
	return 0;
}

int string(char *string)
{
	int interrompe = 0, i=0, cont=0;
	while(*(string+i) != '\0')
	{
		if ((int)*(string+i) >= 'A' && (int)*(string+i) <= 'Z' || (int)*(string+i) >= 'a' && (int)*(string+i) <= 'z')
			cont ++;
		i++;
	}
	return cont;
}
