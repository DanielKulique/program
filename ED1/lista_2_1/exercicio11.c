#include <stdlib.h>
#include <stdio.h>


int caracter_semelhante(char *string1, char *string2);

int main(){
	char str1[] = "Primeira Frase";
	char str2[] = "Primeira ";
	int repetidas=0;
	repetidas = caracter_semelhante(str1, str2);
	printf("Letras repetidas: %d", repetidas);
}

int caracter_semelhante(char *string1, char *string2){
	int i=0, j=0, rep=0;
	
	while(string1[i] != '\0'){
		j=0;
		while(string2[j] != '\0'){
			if((int)string1[i] >= 'a' && (int)string1[i] <= 'z' || (int)string1[i] >= 'A' && (int)string1[i] <= 'Z'){
				if(string1[i] == string2[j]){
					rep++;
					break;
				}
			}
			j++;
		}
		i++;
	}
	return rep;
}
