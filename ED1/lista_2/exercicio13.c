#include <stdio.h>
#include <string.h>
#include <ctype.h>

void string(char *string);


int main()
{
	int i=0;
	char nome[100];
	printf("\nDigite a frase:");
	fgets(nome, 100, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	string(nome);
	
	while(nome[i] != '\0')
	{
		printf("%c", nome[i]);
		i++;
	}
	printf("\n");
	return 0;
}

void string(char *string)
{
	int i=0;
	while(*(string+i) != '\0')
	{
		string[i] = toupper(*(string+i));
		i++;
	}
}
