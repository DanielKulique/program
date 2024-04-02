#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *str);

int main()
{

	char string[] = "daniel ricardo";
	char *string2;
	string2 = strcopy(string);
	if (string2 != NULL)
	{
		printf("%s", string2);
		free(string2);
	}
	else
		printf("erro ao copiar string\n");
		
	return 0;	
}

char *strcopy(char *str)
{
	int tamanho=0;
	int i=0;
	
	while(str[tamanho] != '\0')
	{
		tamanho++;
	}
	char *copia = (char *)malloc((tamanho + 1) * sizeof(char)); // alocar
	if (copia == NULL){
		printf("Erro ao alocar memoria\n");
		return NULL;
	}
	
	for(int i = 0; i<= tamanho; i++)
	{
		copia[i] = str[i];
	}
	copia[tamanho] = '\0';
	return copia;
}
