// Crie um programa que compara duas strings (não use a função ao strcmp).

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    char frase[7] = "abcd";
    char frase2[7] = "abcd";
    //printf("\nDigite sua Frase 1:");
    //scanf("%s", frase);
    //printf("\nDigite sua Frase 2:");
    //scanf("%s", frase2);s

    while(frase[i] != '\0'){
        if(frase[i] != frase2[i]){
            printf("\nDiferenca encontrada!");
            break;
        }
        else 
            printf("\nTudo Ok!");
        i++; 
    }
    //printf("%d", i);
    return 0;
}