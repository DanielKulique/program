//.Escreva um programa que recebe uma string S e inteiros não-negativos I e J e imprima
//o segmento S[I..J]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0, j=0, parar=0, k=0;
    char string[100];

    printf("\nDigite Sua String: "); 
    fgets(string, sizeof(string), stdin);

    while (parar == 0)
    {
        printf("\nDigite um numero positivo para I[INICIO]: ");
        scanf("%d", &i);
        printf("\nDigite um numero positivo para J[FIM] (j maior que i): ");
        scanf("%d", &j);
        if ( i>= 0 && j>=0 && j > i)
            parar = 1;
        else if (j<i)
            printf("\nJ deve ser maior!");
        else
            printf("\n Digite valores positivos");

    }

    printf("\nSegmento de Frase [%d..%d]: ", i, j);
    for(k=i; k<=j; k++)
    {
        printf("%c", string[k]);
    }

    return 0;
}