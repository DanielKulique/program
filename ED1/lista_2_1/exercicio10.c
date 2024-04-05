//Reescreva as funções strlen, strcpy, strlwr, strupr, strchr e strcat da biblioteca <string.h> usando
//ponteiros
#include <stdio.h>
#include <stdlib.h>

int *alocar_memoria(int tamanho);
void desaloca(char **p);
int strTam(char *str);
char *strCopia(char *str, int tam);
char *strBaixo(char *str, int tam);
char *strAlto(char *str, int tam);
char *strConcatena(char *str1, char *str2, int tam);

int main(){
	char string[] = "Frase de teste";
	char string2[] = "Cotinuacao Frase";
	int tama;
	char *copi=NULL, *minus=NULL, *maius=NULL, *nova_frase=NULL;
	tama = strTam(string);
	printf("\nTamanho %d", tama);
	copi = strCopia(string, tama); //tama = endereço de tama
	minus = strBaixo(string, tama);
	maius = strAlto(string, tama);
	nova_frase = strConcatena(string, string2, tama);
	printf("\nCopia %s", copi);
	printf("\nMinuscula %s", minus);
	printf("\nMaiuscula %s", maius);
	printf("\nFrase Contatena %s", nova_frase);
	desaloca(&copi);
	desaloca(&minus);
	desaloca(&maius);
	desaloca(&nova_frase);
	return 0;
}

int *alocar_memoria(int tamanho)
{
	int *ptr = NULL;
	ptr = (int *)malloc(sizeof(int)*tamanho);
	if(ptr)
		return ptr;
	else 
		return NULL;
}

void desaloca(char **p)
{
	if(*p)
	{
		free(*p);
		*p = NULL;
	}
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
char *strCopia(char *str, int tam)//
{
	int i=0; 
	char *copia=NULL;
	copia = (char *)malloc(tam*sizeof(char));
	if(copia){
		while(str[i] != '\0'){
			copia[i] = str[i];
			i++;
		}
		copia[i] = '\0';
		return copia; //PRECISA DESALOCAR
	}
	else
		return NULL;
}

char *strBaixo(char *str, int tam)
{
	int i=0, j=0;
	char *caixa_baixa=NULL;
	caixa_baixa = (char *)malloc(tam*sizeof(char));
	
	if(caixa_baixa){
		while(str[i] != '\0'){
			for(j=0;j<tam;j++){
				if ((int)str[j] >= 'A' && (int)str[j] <= 'Z')
					caixa_baixa[j] = (((int)str[j])+32);
				else
					caixa_baixa[j] = str[j];
			}
			i++;
		}
		caixa_baixa[i] = '\0';
		return caixa_baixa; //PRECISA DESALOCAR
	}
	else
		return NULL;
}

char *strAlto(char *str, int tam)
{
	int i=0, j=0;
	char *caixa_alta=NULL;
	caixa_alta = (char *)malloc(tam*sizeof(char));
	
	if(caixa_alta){
		while(str[i] != '\0'){
			for(j=0;j<tam;j++){
				if ((int)str[j] >= 'a' && (int)str[j] <= 'z')
					caixa_alta[j] = (((int)str[j])-32);
				else
					caixa_alta[j] = str[j];
			}
			i++;
		}
		caixa_alta[i] = '\0';
		return caixa_alta; //PRECISA DESALOCAR
	}
	else
		return NULL;
}

char *strConcatena(char *str1, char *str2, int tam){
	int i=0, j=0;
	char *nova = NULL;
	nova = (char *)malloc(tam*sizeof(char));
	
	if(nova){
		while(str1[i] != '\0'){
			nova[i] = str1[i];
			i++;
		}
		while(str2[j] != '\0'){
			nova[i + j] = str2[j];
			j++;
		}
		nova[i + j] = '\0';
		return nova; //PRECISA DESALOCAR
	}
	else 
		return NULL; 
}












