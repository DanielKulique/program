//Faça um programa que receba duas frases distintas e imprima de maneira invertida,
//trocando as letras A por *

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char frase[100];
}String;


int main(){
    int i=0, j=0,tam=0;

    String iniciar[2];

    for (i=0; i<2; i++)
    {
        printf("Digite a frase %d:", i);
        fgets(iniciar[i].frase, sizeof(iniciar[i].frase), stdin);
    }
    
    for (i=0; i<2; i++){   
        printf("Frase %d: ",i);

        tam = strlen(iniciar[i].frase);
        for(j=tam; j>=0; j--){
            if (iniciar[i].frase[j] == 'A' || iniciar[i].frase[j] == 'a')
                iniciar[i].frase[j] = '*';
            printf("%c ", iniciar[i].frase[j]);
        }
        printf("\n");
    }

    return 0;
}