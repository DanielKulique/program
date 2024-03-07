//Escreva um programa que substitui as ocorrências de um caractere 0 em uma string por
//outro caractere 1.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    char string[10], aux[10];
    printf("\nDigite seu numero: ");
    scanf("%s", string);

    while(string[i] != '\0'){
        aux[i] = string[i];
        i++;
    }
    i = 0;
    while(string[i] != '\0'){
        if (string[i] == '0')    
            string[i] = '1';
        i++;
    }
    
    printf("\nString original: [%s]", aux);
    printf("\nOcorrencias substituidas: [%s]", string);
}