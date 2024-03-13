//Faça um programa que preencha um vetor com os modelos de cinco carros (exemplos
//de modelos: Fusca, Gol, Vectra, etc.). Preencha outro vetor com o consumo desses
//carros, isto é, quantos quilómetros cada um deles faz com um litro de combustível.
//Calcule e mostre: (a) O modelo de carro mais econômico; (b) Quantos litros de
//combustível cada um dos carros cadastrados consomem para percorrer uma distancia de
//1.000 quilômetros. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
    {
        char modelo[100];
        int consumo;

    } Tabela;

int main(){
    int i=0;
    int menor_consumo = 0;
    char mais_economico[10];

    Tabela carro[5];
    
    strcpy(carro[0].modelo, "Fusca");
    carro[0].consumo = 12;
    strcpy(carro[1].modelo, "Vectra");
    carro[1].consumo = 7;
    strcpy(carro[2].modelo, "Ford");
    carro[2].consumo = 10;
    strcpy(carro[3].modelo, "toyota");
    carro[3].consumo = 14;
    strcpy(carro[4].modelo, "Gol");
    carro[4].consumo = 16;

    menor_consumo = carro[0].consumo;
    strcpy(mais_economico, carro[0].modelo);
    for (i=0; i<5; i++){
        if (menor_consumo > carro[i].consumo)
        {
            menor_consumo = carro[i].consumo;
            strcpy(mais_economico, carro[i].modelo);
        }
    }

    printf("\nCarro mais economico [%s] ", mais_economico);

    for (i=0; i<5; i++)
    {
        printf("\n%s consome %d litros para rodar 1000km", carro[i].modelo, (carro[i].consumo * 1000));
    }

    return 0;
}

