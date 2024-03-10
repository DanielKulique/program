//Faça um programa que receba uma palavra e a imprima de trás-para-frente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, tamanho;
    char string[10];
    printf("\nDigite Sua String: ");
    scanf("%s", string);
    tamanho = strlen(string);
    
    for(i=tamanho; i>=0; i--){
        printf("%c", string[i]);
    }
}