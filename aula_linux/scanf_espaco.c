#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	int len, i;
	char nome[80];
	printf("Digite o seu nome: ");
	fgets(nome,80,stdin);
	len=strlen(nome);
	for(i=0; i<len + 4; i++) //+4 faz leitura ilegal no vetor nome
	{
		printf("Endereço = %x\tChar = %c\t Inteiro = %d\n", (nome+i), nome[i], (int)nome[i]);
	}
	return 0; 
} 
