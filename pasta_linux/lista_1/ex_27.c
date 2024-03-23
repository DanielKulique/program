/*Faça um programa que, dada uma string, diga se ela e um palíndromo ou não.
Lembrando que um palíndromo e uma palavra que tenha a propriedade de poder ser lida
tanto da direita para a esquerda como da esquerda para a direita. Exemplo: ovo arara
Socorram-me, subi no ônibus em Marrocos. Anotaram a data da maratona*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, j, s=0;
	
	char string[100], string2[100];
	printf("\nDigite a frase 1: ");
	fgets(string, 100, stdin);
	
	printf("\nDigite a frase 2: ");
	fgets(string2, 100, stdin);

	//remover o enter \n da string
	string[strcspn(string, "\n")] = '\0';
	string2[strcspn(string2, "\n")] = '\0';

	j = strlen(string2)-1;
	for(i=0; i<strlen(string); i++)
	{
		printf("\n%c i=%d", string[i], i);
		printf("\n%c j=%d", string2[j], j);
		if(string[i] != string2[j])
		{			
			printf("\ndiferenca encontrada");
			s=1;
			break;	
		}
		j--;
	}	
//	printf("\nS1: %s \nS2: %s", string, string2);
	if(s==0)
		printf("\nfrase palindroma");	
	return 0;
}
