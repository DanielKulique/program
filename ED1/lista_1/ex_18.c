//Faça um programa em que troque todas as ocorrências de uma letra L1 pela letra L2 em
//uma string. A string e as letras L1 e L2 devem ser fornecidas pelo usuário.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, tam=0;
    char L1, L2, string[100], s_modificada[100];

    printf("\nDigite sua string: ");
    fgets(string, 100, stdin);
    printf("\nSua String e: %s", string);
    printf("\nCaracter a ser substituido: ");
    scanf(" %c", &L1);
    printf("\nNovo Caracter desejado: ");
    scanf(" %c", &L2);
    tam = strlen(string);
    //s_modificada[100] = string[100];

    for (i=0; i<=tam; i++)
        if(string[i] == L1)
            s_modificada[i] = L2;
        else
            s_modificada[i] = string[i];

    printf("\nString Antiga: %s", string);
    printf("\nNova String: %s", s_modificada);

    return 0;
}