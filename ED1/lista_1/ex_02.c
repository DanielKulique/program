//Crie um programa que calcula o comprimento de uma string (nao use a função strlen).

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    char frase[10];
    printf("\nDigite sua Frase:");
    scanf("%s", frase);
    while(frase[i] != '\0'){
        i++; 
    }
    printf("%d", i);
    return 0;
}