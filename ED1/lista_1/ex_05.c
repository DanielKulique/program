//Digite um nome, calcule e retorne quantas letras tem esse nome. 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=0;
    char nome[10];
    printf("\nDigite seu nome: ");
    scanf("%s", nome);
    while(nome[i] != '\0'){
        i++;
    }
    printf("\nLetras no nome: %d", i);
}