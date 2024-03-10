//Faça um programa que leia uma palavra (máximo de 50 letras) e some 1 no valor ASCII
//de cada caractere da palavra. Imprima a string resultante

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, tam=0;
    char palavra[51];
    printf("\n Digite sua palavra: ");
    fgets(palavra, 51, stdin);
    tam = strlen(palavra);
    printf("\nPalavra com +1 no valor do caracter ascii:\n");
    for (i=0; i<tam; i++)
        printf("%c", palavra[i]+1);
    return 0;
}