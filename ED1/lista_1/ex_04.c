// Faça um programa que leia um nome e imprima as 4 primeiras letras do nome

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    char nome[7];
    printf("\nDigite seu Nome:");
    scanf("%s", nome);
    
    for (i=0; i<4; i++)
        printf("%c", nome[i]);
    
    return 0;
}