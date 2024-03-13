//Escreva um programa que recebe do usuário uma string S, um caractere C, e uma
//posição I e devolve o índice da primeira posição da string onde foi encontrado o
//caractere C. A procura deve começar a partir da posição I.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, parar=0, k=0;
    char string[100];
    char caracter;

    printf("\nDigite Sua String: "); 
    fgets(string, sizeof(string), stdin);
    printf("\nDigite seu caracter: "); 
    scanf(" %c", &caracter);

    while (parar == 0)
    {
        printf("\nDigite um numero positivo para I[INICIO DA BUSCA]: ");
        scanf("%d", &i);
        if ( i>= 0 && i < (int)strlen(string))
            parar = 1;
        else
            printf("\n Digite valores positivos");

    }

    printf("\nProcurando...");
    for(k=i; k < (int)strlen(string); k++)
    {
        printf("%c", string[k]);
    }
    for(k=i; k < (int)strlen(string); k++)
    {
        if (string[k] == caracter)
            printf("\nLetra %c encontrada na posicao %d da string: ", caracter, k);
    }

}