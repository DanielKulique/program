#include <stdio.h>
#include <stdlib.h>

char *uniao_vet(char *vet1, char *vet2, int tam);
int *alocar_memoria(int tamanho); //retorna um endereço de memoria, por isso tem que ser int
int strTam(char *str);

int main(){
	char str1[] = "Primeira Frase";
	char str2[] = "Segunda";
	int tam=0;
	tam = (strTam(str1) + strTam(str2));
	
	return 0;
}

int strTam(char *str) //retorna um inteiro;
{
	int tamanho=0;
       	while (str[tamanho] != '\0') 
        {
        	tamanho++;
        }
	return tamanho;
}

char *uniao_vet(char *vet1, char *vet2, int tam){
	char *concatena;
	int i=0, j=0;
	concatena = alocar_memoria(tam); //aloca concatena dinamicamente, receba; 
	
}

int *alocar_memoria(int tamanho)
{
	int *ptr = NULL;
	ptr = (char *)malloc(sizeof(char)*tamanho); //em char, pq se for int não faz sentido;
	if(ptr)
		return ptr;
	else 
		return NULL;
}
