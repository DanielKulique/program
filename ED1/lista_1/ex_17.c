//.Leia um vetor contendo letras de uma frase inclusive os espaços em branco. Retirar os
//espaços em branco do vetor e depois escrever o vetor resultante.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, j=0, tam=0;
    char frase[100], novafrase[100];
    printf("\nEscreva sua string: ");
    fgets(frase, 100, stdin);
    tam = strlen(frase);
    for(i=0; i<tam; i++){
        if(frase[i] != ' ')
            novafrase[j++] = frase[i];
    }
    novafrase[j] = '\0';
    //tam = strlen(novafrase);
    //for(i=0; i<tam; i++){
    printf("%s", novafrase);
    //}
    return 0;
}