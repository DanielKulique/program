//Faça um programa que receba do usuário uma string. O programa imprime a string sem
//suas vogais

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int i, tamanho;
    char string[10];
    printf("\nDigite Sua String: ");
    scanf("%s", string);
    tamanho = strlen(string);
    
    for(i=0; i<tamanho; i++){
        if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u')
            printf("%c", string[i]);
    }
}