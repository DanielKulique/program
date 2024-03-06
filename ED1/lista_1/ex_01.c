//Faça um programa que então leia uma string e a imprima

#include <stdio.h>
#include <stdlib.h>

int main(){
    char frase[10];
    printf("\nDigite sua Frase:");
    scanf("%s", frase);
    printf("%s", frase);
    return 0;
}