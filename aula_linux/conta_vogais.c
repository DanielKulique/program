#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conta_vogais(char string[], int *num_vogais, int *num_consoantes);

int main()
{
	char nome[100];
	int vogais=0, consoantes=0;
	
	fgets(nome, 100, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	conta_vogais(nome, &vogais, &consoantes);
	printf("\nQuantidade de vogais: [%d}", vogais);
	printf("\nQuantidade de consoantes: [%d}", consoantes);
	
	return 0;
}

void conta_vogais(char string[], int *num_vogais, int *num_consoantes)
{
	int i=0;
	
	for (i=0; i<strlen(string); i++)
	{
		if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
		{
			*num_vogais += 1;
			printf("\nvogal - %c", string[i]);
		}
		else
		{
			if((int)string[i] >= 97 && (int)string[i] <=122)
			{
				*num_consoantes += 1;
				printf("\nconsoante - %c", string[i]);
			}
		}
	}
	printf("%d", i);
}
